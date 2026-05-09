import streamlit as st
import pandas as pd
import plotly.express as px

st.set_page_config(layout="wide", page_title="VHI data analysis")

@st.cache_data
def load_data():
    df = pd.read_csv('vhi_data.csv')
    df.columns = df.columns.str.strip()
    return df

df = load_data()

# init values for filters
DEFAULT_VALUES = {
    'index': 'VHI',
    'region': df['region'].unique()[0],
    'weeks': (int(df['week'].min()), int(df['week'].max())),
    'years': (int(df['year'].min()), int(df['year'].max())),
    'sort_asc': False,
    'sort_desc': False
}

# session_state
for key, val in DEFAULT_VALUES.items():
    if key not in st.session_state:
        st.session_state[key] = val

# reset filters func
def reset_filters():
    for key, val in DEFAULT_VALUES.items():
        st.session_state[key] = val

# Columns
col_sidebar, col_main = st.columns([1, 3])

with col_sidebar:
    st.header("Filters")
    
    # Dropdown for time series (VCI, TCI, VHI. Task1)
    index_choice = st.selectbox("Choose time series:", ['VCI', 'TCI', 'VHI'], key='index')
    
    # Dropdown for region (Task2)
    region_choice = st.selectbox("Choose region:", df['region'].unique(), key='region')
    
    # Slider for week interval (Task3)
    week_range = st.slider("Week interval:",int(df['week'].min()), int(df['week'].max()),key='weeks')
    
    # Slider for year interval (Task4)
    year_range = st.slider("Year interval:",int(df['year'].min()), int(df['year'].max()),key='years')
    
    # Sort by VCI, TCI, VHI (Task8)
    st.subheader("Sort by")
    sort_asc = st.checkbox("Ascending", key='sort_asc')
    sort_desc = st.checkbox("Descending", key='sort_desc')
    
    # if both checkboxes active
    if sort_asc and sort_desc:
        st.warning("You choose both sorting variants. Ascending sort willl be used.")

    # Reset filters button (Task5)
    st.button("Reset filters", on_click=reset_filters)

# Filters
filtered_df = df[
    (df['region'] == region_choice) &
    (df['week'] >= week_range[0]) & (df['week'] <= week_range[1]) &
    (df['year'] >= year_range[0]) & (df['year'] <= year_range[1])
]

# Sort
if sort_asc:
    filtered_df = filtered_df.sort_values(by=index_choice, ascending=True)
elif sort_desc:
    filtered_df = filtered_df.sort_values(by=index_choice, ascending=False)

# Main panel (Tasks 6, 7 and 9)
with col_main:
    st.title(f"{index_choice} index analysis for {region_choice} region")
    
    tab_table, tab_chart, tab_compare = st.tabs(["Table", "Time series", "Regions comparison"])
    
    # filtered df show tab
    with tab_table:
        st.subheader("Filtered data")
        st.dataframe(filtered_df, use_container_width=True)
    
    # Time series tab
    with tab_chart:
        st.subheader(f"{index_choice} Dynamics (Weeks: {week_range[0]}-{week_range[1]})")
        if not filtered_df.empty:
            fig = px.line(filtered_df.sort_values(['year', 'week']),x='year', y=index_choice, color='week')
            st.plotly_chart(fig, use_container_width=True)
        else:
            st.info("No data to show.")

    # Region comparison tab
    with tab_compare:
        st.subheader(f"{index_choice} comparison by regions")
        compare_df = df[(df['week'] >= week_range[0]) & (df['week'] <= week_range[1]) &
            (df['year'] >= year_range[0]) & (df['year'] <= year_range[1])]
        avg_compare = compare_df.groupby('region')[index_choice].mean().reset_index()
        avg_compare = avg_compare.sort_values(by=index_choice, ascending=False)
        avg_compare['Is_Selected'] = avg_compare['region'] == region_choice
    
        fig_compare = px.bar(avg_compare, x='region', y=index_choice, color='Is_Selected', color_discrete_map={True: 'red', False: 'blue'},
                             title=f"{index_choice} mean by chosen period", labels={'Is_Selected': 'Selected region'})
        st.plotly_chart(fig_compare, use_container_width=True)