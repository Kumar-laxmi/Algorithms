import math

key = "HACK"


def encryptMessage(msg):
    cipher = ""
    key_index = 0  # keeps track of key indices
    msg_len = float(len(msg))
    msg_list = list(msg)
    key_list = sorted(list(key))  # Alphabetically sorting the key

    # calculate column of the matrix
    col = len(key)

    # calculate maximum row of the matrix
    row = int(math.ceil(msg_len/col))

    # Adding the padding character '_' in empty cell of the matrix
    fill_null = int((row*col) - msg_len)
    msg_list.extend('_' * fill_null)

    # Creating a matrix and inserting message and padding character row wise
    matrix = [msg_list[i: i+col]
              for i in range(0, len(msg_list), col)]

    for _ in range(col):
        current_index = key.index(key_list[key_index])
        cipher += ''.join([row[current_index]
                          for row in matrix])
        key_index += 1
    return cipher


def decryptMessage(cipher):
    msg = ""
    key_index = 0  # keeps the track of key indices

    msg_index = 0
    msg_len = float(len(cipher))
    msg_list = list(cipher)

    # Column of the matrix
    col = len(key)

    # Maximum row of the matrix
    row = int(math.ceil(msg_len/col))

    key_list = sorted(list(key))

    dec_cipher = []
    for _ in range(row):
        dec_cipher += [[None] * col]

    for _ in range(col):
        curr_index = key.index(key_list[key_index])

        for j in range(row):
            dec_cipher[j][curr_index] = msg_list[msg_index]
            msg_index += 1
        key_index += 1

    msg = ''.join(sum(dec_cipher, []))

    null_count = msg.count('_')

    if null_count > 0:
        return msg[: -null_count]

    return msg


message = input('Enter the plain text: ')

cipher = encryptMessage(message)
print("Encrypt Message", cipher)

decryptedText = decryptMessage(cipher)
print("Decrypted Message", decryptedText)
