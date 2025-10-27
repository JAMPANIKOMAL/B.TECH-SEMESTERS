# Practical 08: Text Preprocessing Steps
# Save this file as p08.py

import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from nltk.stem import WordNetLemmatizer
from sklearn.feature_extraction.text import CountVectorizer
import re

# --- Download NLTK data ---
# This only needs to be run once
try:
    nltk.data.find('tokenizers/punkt')
except LookupError:
    print("Downloading 'punkt' tokenizer...")
    nltk.download('punkt', quiet=True)

try:
    nltk.data.find('corpus/stopwords')
except LookupError:
    print("Downloading 'stopwords'...")
    nltk.download('stopwords', quiet=True)

try:
    nltk.data.find('corpora/wordnet')
except LookupError:
    print("Downloading 'wordnet' lemmatizer...")
    nltk.download('wordnet', quiet=True)

print("--- Practical 08: Text Preprocessing ---")

# --- Sample Text Dataset ---
text_data = [
    "The quick brown fox jumped over the lazy dogs.",
    "A journey of a thousand miles begins with a single step.",
    "Data preprocessing is an important step in machine learning.",
    "He was running and looking at the cats."
]

print(f"\n1. Original Text Data:\n{text_data}\n")

# --- Step 1: Tokenization (and Lowercasing) ---
print("\n--- 2. Tokenization & Lowercasing ---")
# Also convert to lowercase and remove punctuation
tokenized_docs = []
for doc in text_data:
    # Remove punctuation and numbers
    doc = re.sub(r'[^a-zA-Z\s]', '', doc, re.I|re.A)
    doc = doc.lower()
    tokens = word_tokenize(doc)
    tokenized_docs.append(tokens)

print(f"Tokenized:\n{tokenized_docs[0]}\n")

# --- Step 2: Stop Words Removal ---
print("\n--- 3. Stop Words Removal ---")
stop_words = set(stopwords.words('english'))
filtered_docs = []
for doc_tokens in tokenized_docs:
    filtered_tokens = [word for word in doc_tokens if word not in stop_words]
    filtered_docs.append(filtered_tokens)

print(f"Original Tokens:\n{tokenized_docs[0]}")
print(f"Tokens after Stop Words Removal:\n{filtered_docs[0]}\n")

# --- Step 3: Stemming ---
print("\n--- 4. Stemming (using PorterStemmer) ---")
stemmer = PorterStemmer()
stemmed_docs = []
for doc_tokens in filtered_docs:
    stemmed_tokens = [stemmer.stem(word) for word in doc_tokens]
    stemmed_docs.append(stemmed_tokens)

print(f"Original Tokens:\n['running', 'looking', 'dogs']")
print(f"Stemmed Tokens:\n['{stemmer.stem('running')}', '{stemmer.stem('looking')}', '{stemmer.stem('dogs')}']\n")
print(f"Full stemmed doc 0:\n{stemmed_docs[0]}\n")

# --- Step 4: Lemmatization ---
print("\n--- 5. Lemmatization (using WordNet) ---")
lemmatizer = WordNetLemmatizer()
lemmatized_docs = []
for doc_tokens in filtered_docs:
    # Note: Lemmatization can be improved by providing Part-of-Speech tags
    lemmatized_tokens = [lemmatizer.lemmatize(word) for word in doc_tokens]
    lemmatized_docs.append(lemmatized_tokens)

print(f"Original Tokens:\n['running', 'looking', 'dogs', 'cats']")
print(f"Lemmatized Tokens:\n['{lemmatizer.lemmatize('running')}', '{lemmatizer.lemmatize('looking')}', '{lemmatizer.lemmatize('dogs')}', '{lemmatizer.lemmatize('cats')}']\n")
print(f"Full lemmatized doc 0:\n{lemmatized_docs[0]}\n")


# --- Step 5: Bag of Words (BoW) ---
print("\n--- 6. Bag of Words (BoW) Model ---")
# We use the lemmatized documents for BoW
# CountVectorizer needs strings, not lists of tokens, so we join them back
processed_docs = [" ".join(tokens) for tokens in lemmatized_docs]

vectorizer = CountVectorizer()
bow_matrix = vectorizer.fit_transform(processed_docs)

# Get the feature names (the vocabulary)
feature_names = vectorizer.get_feature_names_out()

print(f"Processed Docs (as strings):\n{processed_docs}\n")
print(f"BoW Vocabulary (Unique Words):\n{feature_names}\n")
print(f"BoW Matrix (Document-Term Matrix):\n{bow_matrix.toarray()}\n")

print("--- End of Practical 08 ---")
