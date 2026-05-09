### Made with Python 3.13.5
###  To install requirements run:
`pip install -r requirements.txt`

### Short instruction how to use:
1. This script requires 'vhi_data.csv' file with already cleaned data. \
You can download it from this repo (in "lab5" folder) \
Or you can make it by yourself (if you need relevant data):
- Download script "part1.ipynb" from "lab2" folder (dont forget to install requirements);
- Run 5 first cells with code
- Add this code in a new cell and run it \
 `df.to_csv('vhi_data.csv', index=False, encoding='utf-8-sig')`
- Copy 'vhi_data.csv' to a folder with 'lab5.py' script

2. Now you can run script using: \
`streamlit run lab5.py`
