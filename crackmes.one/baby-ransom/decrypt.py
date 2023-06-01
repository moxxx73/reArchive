#!/usr/bin/env python3
import os
import struct

dirents = os.scandir()
for ent in dirents:
    if('.corona' in ent.name):
        name = ent.name.replace('.corona', '')
        fdr = open(ent.name, 'rb')
        fdw = open(name, 'wb')
        enc_data = fdr.read()
        fdr.close()
        for b in enc_data:
            fdw.write(struct.pack('B', b^0x5c))

        fdw.close()
        print(f'Decrypted file: {name:s}')