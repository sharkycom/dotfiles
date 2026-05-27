#arxikopoisi listas gia onomata kai vathmous
names = []
scores = []

while True:
    #emfanizei to menu
    print("=== ΣΥΣΤΗΜΑ ΔΙΑΧΕΙΡΙΣΗΣ ΑΘΛΗΤΩΝ ===")
    print("1. Προσθήκη Νέου Αθλητή")
    print("2. Διαγραφή Αθλητή από το Μητρώο")
    print("3. Εμφάνιση Κατάστασης Αθλητών")
    print("4. Στατιστική Ανάλυση")
    print("5. Έξοδος")
    
    epilogi = input("Δώσε την επιλογή σου (1-5): ")

    if epilogi == "1":
        #prosthiki neou athliti
        onoma = input("Δώσε το ονοματεπώνυμο του αθλητή: ")
        #vathmologia
        taxythta = float(input("Δώσε βαθμολογία Ταχύτητας (0-10): "))
        dynami = float(input("Δώσε βαθμολογία Δύναμης (0-10): "))
        texniki = float(input("Δώσε βαθμολογία Τεχνικής (0-10): "))
        foul = int(input("Δώσε τον αριθμό των φάουλ: "))
        #ypologismos vathmou
        vathmos = (taxythta * 0.4) + (dynami * 0.3) + (texniki * 0.3)
        #poinologio
        if foul >= 6:
            vathmos = 0
        elif foul == 5:
            vathmos = vathmos - 2
        elif foul == 3 or foul == 4:
            vathmos = vathmos - 1
        #check arnitikou arithmou
        if vathmos < 0:
            vathmos = 0
        #apothikeusi dedomenon
        names.append(onoma)
        scores.append(vathmos)
        print("Ο αθλητής καταχωρήθηκε με επιτυχία!")
    #diagrafi athliti
    elif epilogi == "2":
        diagrafi = input("Ποιον αθλητή θέλεις να διαγράψεις; ")
        if diagrafi in names:
            #diagrafi apo tis 2 listes
            thesi = names.index(diagrafi)
            names.pop(thesi)
            scores.pop(thesi)
            print("Ο αθλητής διαγράφηκε επιτυχώς.")
        else:
            print("Ο αθλητής δεν βρέθηκε.")

    elif epilogi == "3":
        #emfanisi katastasis athlitwn
        if len(names) == 0:
            print("Το μητρώο είναι άδειο.")
        else:
            print("--- Λίστα Αθλητών ---")
            for i in range(len(names)):
                print(i + 1, ".", names[i], "-", scores[i])

    elif epilogi == "4":
        #statistiki analisi
        if len(names) > 0:
            mesos_oros = sum(scores) / len(scores)
            kalyteros = max(scores)
            print("Μέσος Όρος:", mesos_oros)
            print("Καλύτερος Βαθμός:", kalyteros)
        else:
            print("Δεν υπάρχουν δεδομένα.")

    elif epilogi == "5":
        #eksodos
        print("Κλείσιμο συστήματος... Αντίο!")
        break

    else:
        #lathos epilogi
        print("Άκυρη επιλογή.")