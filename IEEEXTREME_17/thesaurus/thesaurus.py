import xml.etree.ElementTree as ET
import re
from collections import defaultdict

# Parse the thesaurus and build a data structure to represent the relationships
thesaurus = defaultdict(list)

xml_input = []
in_xml = False

while True:
    try:
        line = input()
    except EOFError:
        break

    xml_input.append(line)

    if line.strip() == "</Thesaurus>":
        break

xml_content = '\n'.join(xml_input)
root = ET.fromstring(xml_content)

for term_info in root.findall("TermInfo"):
    term = term_info.find("T").text.lower()
    narrower_terms = [nt.text.lower() for nt in term_info.findall("NT")]
    broader_terms = [bt.text.lower() for bt in term_info.findall("BT")]
    synonyms = [syn.text.lower() for syn in term_info.findall("UF")]
    thesaurus[term] = broader_terms + synonyms
    for t in narrower_terms:
        if thesaurus[t]:
            thesaurus[t] += term
        else:
            thesaurus[t] = [term]

# Initialize a dictionary to count the occurrences of each topic
topic_counts = defaultdict(int)
# Process the article text
text = ''.join(input()).lower()  # Process the text and convert to lowercase
text = re.sub(r'[.,?!]', '', text)  # Remove punctuation
words = text.split()

# Function to find the top-level topic for a term
def find_top_level_topic(term):
    for topic, broader_terms in thesaurus.items():
        if term in broader_terms:
            return find_top_level_topic(topic)
    return term

# # Function to find the top-level topic for a term
# def find_top_level_topic(term):
#     if term in thesaurus:
#         broader_terms = thesaurus[term]
#         if not broader_terms:
#             return term  # This is a top-level topic
#         top_level_topics = set()
#         for broader_term in broader_terms:
#             parent_topic = find_top_level_topic(broader_term)
#             if parent_topic:
#                 top_level_topics.add(parent_topic)
#         if len(top_level_topics) == 1:
#             return top_level_topics.pop()
#     return None

# Count the occurrences of terms and their top-level topics
for sz in range(1, len(words)):
    for i in range(len(words)):
        if i+sz > len(words):
            break
        phrase = ' '.join(words[i:i+sz])
        topic = find_top_level_topic(phrase)
        topic_counts[topic] += 1

# Filter out topics that are not top-level (i.e., they are broader terms)
top_level_topics = set(thesaurus.keys())
final_counts = {topic: count for topic, count in topic_counts.items() if topic in top_level_topics}

# Sort and format the output
sorted_counts = sorted(final_counts.items(), key=lambda x: (-x[1], x[0]))
for topic, count in sorted_counts:
    print(f"{topic} = {count}")