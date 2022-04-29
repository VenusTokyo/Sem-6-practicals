def encrypt(txt, key):
    s = ""
    for i in range(len(txt)):
        ch = txt[i]
        if ch.isupper():
            ch = chr((ord(ch) + key - 65) % 26 + 65)
            s += ch
        else:
            ch = chr((ord(ch) + key - 97) % 26 + 97)
            s += ch
    return(s)

def decrypt(txt, key):
    s = ""
    for i in range(len(txt)):
        ch = txt[i]
        if ch.isupper():
            ch = chr((ord(ch) - key - 65) % 26 + 65)
            s += ch
        else:
            ch = chr((ord(ch) - key - 97) % 26 + 97)
            s += ch
    return(s)

def main():
    print("\t\t\t***********CAESER CIPHER***************\n")
    print("Enter your choice\n")
    print("1. Encryption\n")
    print("2. Decryption\n") 
    choice =  input()
    msg =  input("Enter your message")
    key = ord(input("Enter key"))
    if(choice == '1'):
        print("Plain text: ", msg)
        print("Cipher text: ", encrypt(msg, key))
    elif(choice == "2"):
        print("Cipher text: ", msg)
        print("Plain text: ", decrypt(msg, key))
    else:
        print("Wrong choice \n TRY AGAIN")        
main()

