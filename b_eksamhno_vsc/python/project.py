def epilogi_proiontos():
    print("1. Σάντουιτς (2.50€)")
    print("2. Τοστ (1.80€)")
    print("3. Κρουασάν (1.50€)")
    print("4. Τυρόπιτα (2.00€)")

    while True:
        epilogi = int(input("Επιλέξτε προϊόν (1-4): "))
        
        if 1 <= epilogi <= 4:
            break
        else:
            print("Λάθος επιλογή!")

    if epilogi == 1:
        return 2.50  
    elif epilogi == 2:
        return 1.80  
    elif epilogi == 3:
        return 1.50  
    else:
        return 2.00 
timi = epilogi_proiontos()
print(f"Η τιμή του προϊόντος είναι: {timi}€")