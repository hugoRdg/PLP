# sizeof_types.py

import sys

print("Taille des types de base en Python :")

print(f"int : {sys.getsizeof(int())} octets")
print(f"float : {sys.getsizeof(float())} octets")
print(f"bool : {sys.getsizeof(bool())} octets")
print(f"str : {sys.getsizeof('')} octets")
print(f"list : {sys.getsizeof([])} octets")
print(f"tuple : {sys.getsizeof(())} octets")
print(f"dict : {sys.getsizeof({})} octets")