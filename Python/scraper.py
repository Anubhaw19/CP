from bs4 import BeautifulSoup
import requests
import json
import unicodedata
from concurrent.futures import ThreadPoolExecutor,as_completed


# Function to pasre job_description
def parse_paragraph(text):
    soup = BeautifulSoup(text, 'html.parser')
    text = unicodedata.normalize("NFKD", str(soup)) #convert the Unicode escape sequence like "\u00a0" into the corresponding HTML entity representation
    soup = BeautifulSoup(text, 'html.parser') #parse again the modified HTML string
    paragraph_tags = soup.find_all('p') #extract all contents within <p> tag of the HTML string
    txt=''
    for p in paragraph_tags:
        txt+=" "+p.get_text()
    my_list= txt.split('.')
    return list(filter(None, my_list)) # returns a list after filtering Nulls

# Function to pasre Qualification details
def parse_list(text):
    soup = BeautifulSoup(text, 'html.parser') #convert the Unicode escape sequence like "\u00a0" into the corresponding HTML entity representation
    text = unicodedata.normalize("NFKD", str(soup)) #parse again the modified HTML string
    soup = BeautifulSoup(text, 'html.parser')
    paragraph_tags = soup.find_all('li') #extract all contents within <li> tag of the HTML string
    txt=''
    for li in paragraph_tags:
        txt+=" "+li.get_text()
    my_list= txt.split('.')
    return list(filter(None, my_list)) # returns a list after filtering Nulls

#Function for fetching specific job details
def fecth_job_details(url):
    job_info = requests.get(url).text
    job_details = json.loads(job_info)
    if "department" in job_details:
        department = job_details['department']['label']
        title = job_details['name']
        if "region" in job_details['location']:
            location = job_details['location']['city']+', '+ job_details['location']['region']
        else:
            location = job_details['location']['city']
        description = parse_paragraph( job_details['jobAd']['sections']['jobDescription']['text'])
        qualification = parse_list(job_details['jobAd']['sections']['qualifications']['text'])
        job_type = job_details['typeOfEmployment']['id']
        posted_by = job_details['creator']['name']
     # create a dictionary to store results for each job_url
    details = {
        'title' : title,
        'location' : location,
        'description' : description,
        'qualification'  : qualification,
        'job_type'  : job_type,
        'posted_by' : posted_by
    }
    if department in job_lib:
        job_lib[department].append(details)
    else:
        job_lib[department]= []
        job_lib[department].append(details)
        

# Send a GET request to the website
url = 'https://www.cermati.com/karir'
response = requests.get(url)

# Create a BeautifulSoup object to parse the HTML content
soup = BeautifulSoup(response.text, 'html.parser')

# # Finding specific elements with type script and id initials on the page using beautiful soup find function
json_data = soup.find('script', type='application/json',id="initials")
#storing the result into a python string
data = json.loads(json_data.string)


job_lib = {}
job_urls=[]
data_job = data["smartRecruiterResult"]["all"]["content"]
for job in data_job:
    job_urls.append(job['ref']) # store each job_url in a list

#create ThreadPoolExecutor for multithreading
executor = ThreadPoolExecutor(max_workers=5) # declare the maximum number of concurrent worker threads
# Submit scraping tasks for each URL
tasks = [executor.submit(fecth_job_details, url) for url in job_urls]
# Wait for all tasks to complete / debugging each task
for task in as_completed(tasks):
    try:
        result = task.result()
        print(len(job_lib))
        # Process the result if needed
        # ...
#         with open('solution.json','w') as f:
#             f.write(json.dumps(job_lib))
    except Exception as e:
        print(f"An error occurred: {str(e)}")
        
#  writing the result to a json file       
with open('solution.json','w') as f:
            f.write(json.dumps(job_lib, indent=4))


