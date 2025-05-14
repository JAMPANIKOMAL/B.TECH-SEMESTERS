import heapq
from collections import Counter

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None
    def __lt__(self, other):
        return self.freq < other.freq

def huffman_codes(text):
    freq = Counter(text)
    heap = [Node(ch, fr) for ch, fr in freq.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        a = heapq.heappop(heap)
        b = heapq.heappop(heap)
        merged = Node(None, a.freq + b.freq)
        merged.left = a
        merged.right = b
        heapq.heappush(heap, merged)

    codes = {}
    def generate_codes(node, code=""):
        if node:
            if node.char:
                codes[node.char] = code
            generate_codes(node.left, code + "0")
            generate_codes(node.right, code + "1")

    generate_codes(heap[0])
    return codes

text = input("Enter text: ")
codes = huffman_codes(text)

print("Huffman Codes:")
for ch in codes:
    print(f"{repr(ch)}: {codes[ch]}")