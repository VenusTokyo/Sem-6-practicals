def encrypt(message,k):
    cipher=""
    for i in message:
        if i.isupper():
            cipher+=chr(((ord(i)-65)*k)%26+65)
        elif i.islower():
            cipher+=chr(((ord(i)-97)*k)%26+97)
        else:
            cipher+=" "
    return cipher
def getCoeff(d):
    for i in range(1,26):
        j=int(1)
        eqn=int(1)
        while(eqn>=1):
            eqn=26*i-d*j
            if eqn==1:
                return -j
            j=j+1
def decrypt(cipher,k):
    message=""
    k=getCoeff(k)
    for i in cipher:
        if i.isupper():
            message+=chr(((ord(i)-65)*k)%26+65)
        elif i.islower():
            message+=chr(((ord(i)-97)*k)%26+97)
        else:
            message+=" "
    return message
print("Press \n 1. For encryption \n 2. For decryption")
choice=int(input("Enter your choice: "))
if choice==1:
    key=int(input("Enter a valid numerical key:"))
    plainText=input("Enter your message: ")
    print("Cipher Text:",encrypt(plainText,key))
elif choice==2:
    key=int(input("Enter a valid numerical key:"))
    cipherText=input("Enter your message to be decrypted: ")
    print("Plain Text: ",decrypt(cipherText,key))
else:
    print("Invalid Choice!!")
