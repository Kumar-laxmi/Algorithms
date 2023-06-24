#  SHA-224 is part of the SHA-2 family of hash functions. It works by iteratively processing input data in fixed-size blocks and updating the internal state of the hash algorithm until all data has been processed.
#  Working of SHA 224 :-
#  Message Padding: SHA-224 processes input messages in blocks of 512 bits (64 bytes). If the message length is not a multiple of 64 bytes, it needs to be padded.

#  Initial Hash Values: SHA-224 initializes its internal state with specific constant values.

#  Processing the Message: The block is divided into 32-bit words, and the internal state is updated.
#  The message block undergoes several rounds of transformations, including bitwise operations , logical functions , and cyclic shifts.
#  The internal state is updated after each round of processing to incorporate the current block.

#  Finalization: After processing all the message blocks, the resulting internal state represents the hash value (a Hexa decimal string).

#  Output: The resulting digest is the SHA-224 hash of the input message. It is typically used as a compact representation of the input data, and even a small change in the input will produce a significantly different hash value.

import hashlib

def sha224():
  message = 'This message is to be hashed'
  
  hash_digest = hashlib.sha224()    #hashlib module provides the SHA-224 hash function

  hash_digest.update(message.encode('utf-8'))   #encode() function converts the message into bytes
  
  print( hash_digest.hexdigest())    #hexdigest() function converts the digest into hexadecimal format.

sha224()