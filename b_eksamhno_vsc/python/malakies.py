def analyze_temperatures(temp_list):
    total = sum(temp_list)
    count = len(temp_list)
    avg = total / count
    temp_range = max(temp_list) - min(temp_list)
    return temp_range, avg 
# Διπλή επιστροφή τιμών
# Κυρίως Πρόγραμμα
athens_temps = [32.5, 38.0, 29.4, 41.2, 35.6]
# Υποδοχή δεδομένων σε δύο ξεχωριστές μεταβλητές 
diff, mean_value = analyze_temperatures(athens_temps)
print("Το εύρος θερμοκρασίας είναι:", diff, "βαθμοί.")
print("Ο μέσος όρος είναι:", mean_value, "βαθμοί.")