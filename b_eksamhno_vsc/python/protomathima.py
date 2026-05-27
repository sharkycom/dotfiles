name = input("Εισάγετε το όνομα του φοιτητή: ")
surname = input("Εισάγετε το επώνυμο του φοιτητή: ")
age = int(input("Εισάγετε την ηλικία του φοιτητή: "))

age_se_5_xronia = age + 5
age_prin_3_xronia = age - 3
diplasia_age = age * 2
miso_age = age / 2

print(f"\nΔεδομένα φοιτητή: {name} {surname}")
print(f"Τρέχουσα ηλικία: {age} ετών")
print(f"Ηλικία σε 5 χρόνια: {age_se_5_xronia} ετών")
print(f"Ηλικία πριν από 3 χρόνια: {age_prin_3_xronia} ετών")
print(f"Διπλάσια ηλικία: {diplasia_age} ετών")
print(f"Μισή ηλικία: {miso_age} ετών")