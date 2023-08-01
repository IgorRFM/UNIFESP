from rc4 import RC4

import sys
import os
import subprocess
from PyQt5.QtNetwork import QTcpServer, QTcpSocket, QAbstractSocket
from PyQt5.QtNetwork import *
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5 import *
from ctypes import *
import ctypes
import socket
from random import randint


class Validator(QRegExpValidator):
    def __init__(self, pattern):
        super().__init__(QRegExp(f"[{pattern}]+"))


flag_first_message = True
p_ = 353
alfa_ = 3
Xa_ = 0
Xb_ = 0
Ya_ = 0
Yb_ = 0


class mainWindow(QMainWindow):

    __instancia__ = None

    def __init__(self):
        super().__init__()
        screen_geo = QDesktopWidget().availableGeometry()
        x = int((screen_geo.width() - self.width()) / 2)
        y = int((screen_geo.height() - self.height()) / 2)

        self.setGeometry(x, y, 400, 600)  # posicao x, y, largura, altura
        self.setWindowTitle('Telegram da DeepWeb')
        icone = QIcon('./tuiterr.png')
        self.setWindowIcon(icone)

        # Pegando o IP LOCAL
        self.MyIP = self.get_local_ip()

        # Objeto Servidor
        self.Servidor = QTcpServer()
        self.Servidor.newConnection.connect(self.handle_connection)

        # Objeto Cliente
        self.Cliente = QTcpSocket()
        self.Cliente.readyRead.connect(self.recebeMsg_Cliente)

        # Lista de cores
        self.msgColors = {}

        # Compilando os Codigos C
        self.compilaCodigos()

        # Campo de IP ORIGEM
        self.seu_IP_label = QLabel(self)
        self.seu_IP_label.setText('IP LOCAL')
        self.seu_IP_label.setGeometry(10, 1, 120, 10)
        self.seu_IP_label.setAlignment(Qt.AlignCenter)
        font = QFont()
        font.setPointSize(5)
        self.seu_IP_label.setFont(font)

        self.local_IP = QLineEdit(self)
        self.local_IP.setPlaceholderText(str(self.MyIP))
        self.local_IP.setText(str(self.MyIP))
        self.local_IP.setGeometry(10, 10, 120, 30)
        self.local_IP.setReadOnly(True)

        # Campo de IP DESTINO
        self.text_IP = QLineEdit(self)
        self.text_IP.setPlaceholderText('Digite o IP Destino')
        self.text_IP.setGeometry(10, 60, 120, 30)

        # Campo de PORTA SERVIDOR DESTINO
        self.text_PORT_Destino = QLineEdit(self)
        self.text_PORT_Destino.setPlaceholderText("Porta Destino")
        self.text_PORT_Destino.setGeometry(135, 60, 85, 30)

        # Botão Conectar Cliente
        self.btn_Conectar = QPushButton('Conectar', self)
        self.btn_Conectar.setGeometry(290, 60, 100, 30)
        self.btn_Conectar.clicked.connect(lambda: self.conectar())

        # Botão Ligar Servidor
        self.btn_LigarServidor = QPushButton('Ligar Servidor', self)
        self.btn_LigarServidor.setGeometry(290, 10, 100, 30)
        self.btn_LigarServidor.clicked.connect(lambda: self.start())

        # Campo de PORTA SERVIDOR
        self.text_PORT_Local = QLineEdit(self)
        self.text_PORT_Local.setPlaceholderText("Porta Local")
        self.text_PORT_Local.setGeometry(135, 10, 85, 30)

        # Campo de CHAVE CRIPTOGRAFADORA
        self.text_KEY = QLineEdit(self)
        self.text_KEY.setPlaceholderText('Digite a Chave Cripto')
        self.text_KEY.setGeometry(10, 110, 275, 30)

        # Caixa de Seleção do Algoritmo
        self.opt_ALGORITHMS = QComboBox(self)
        self.opt_ALGORITHMS.addItems(
            ['RC4', 'SDES', 'ECB', 'CBC', 'RC4 + DH', 'SDES + DH'])

        self.opt_ALGORITHMS.setGeometry(290, 110, 100, 30)
        self.opt_ALGORITHMS.currentIndexChanged.connect(self.updateTypeKEY)

        # Titulo do Chat
        self.text_MSGCHAT_LABEL = QLabel(self)
        self.text_MSGCHAT_LABEL.setText('BATE PAPO UOL')
        self.text_MSGCHAT_LABEL.setGeometry(10, 150, 380, 30)
        self.text_MSGCHAT_LABEL.setAlignment(Qt.AlignCenter)
        font = QFont()
        font.setPointSize(15)
        self.text_MSGCHAT_LABEL.setFont(font)

        # Chat 1
        self.text_MSGCHAT = QTextEdit(self)
        self.text_MSGCHAT.setGeometry(10, 180, 380, 130)
        self.text_MSGCHAT.setReadOnly(True)

        # Adicionar sombra nas bordas
        shadow_effect = QGraphicsDropShadowEffect()
        shadow_effect.setBlurRadius(5)  # Definir o raio de desfoque da sombra
        shadow_effect.setColor(QColor(0, 0, 0, 150))  # Definir a cor da sombra
        shadow_effect.setOffset(0, 0)  # Definir o deslocamento da sombra
        self.text_MSGCHAT.setGraphicsEffect(shadow_effect)

        scrollbar = QScrollBar(self)
        scrollbar.setGeometry(380, 200, 20, 300)
        self.text_MSGCHAT.setVerticalScrollBar(scrollbar)

        # Titulo do Chat 2
        self.text_MSGCHAT_LABEL = QLabel(self)
        self.text_MSGCHAT_LABEL.setText('CRIPTOGRAFADO')
        self.text_MSGCHAT_LABEL.setGeometry(10, 330, 380, 30)
        self.text_MSGCHAT_LABEL.setAlignment(Qt.AlignCenter)
        font = QFont()
        font.setPointSize(15)
        self.text_MSGCHAT_LABEL.setFont(font)

        # Chat 2
        self.text_MSGCHAT_CRIPTO = QTextEdit(self)
        self.text_MSGCHAT_CRIPTO.setGeometry(10, 360, 380, 130)
        self.text_MSGCHAT_CRIPTO.setReadOnly(True)

        # Adicionar sombra nas bordas
        shadow_effect = QGraphicsDropShadowEffect()
        shadow_effect.setBlurRadius(5)  # Definir o raio de desfoque da sombra
        shadow_effect.setColor(QColor(0, 0, 0, 150))  # Definir a cor da sombra
        shadow_effect.setOffset(0, 0)  # Definir o deslocamento da sombra
        self.text_MSGCHAT_CRIPTO.setGraphicsEffect(shadow_effect)

        scrollbar = QScrollBar(self)
        scrollbar.setGeometry(380, 200, 20, 300)
        self.text_MSGCHAT_CRIPTO.setVerticalScrollBar(scrollbar)

        # Campo de enviar a mensagem
        self.text_MSG = QLineEdit(self)
        self.text_MSG.setPlaceholderText('Escreva sua mensagem')
        self.text_MSG.setGeometry(10, 520, 275, 30)
        self.text_MSG.installEventFilter(self)

        # Botão Enviar mensagem
        self.btn_Enviar = QPushButton('Enviar', self)
        self.btn_Enviar.setGeometry(290, 520, 100, 30)
        self.btn_Enviar.clicked.connect(lambda: self.enviar_mensagem(
            'servidor', self.opt_ALGORITHMS.currentText()))


# SERVIDOR
######################################

    def start(self):
        if self.text_PORT_Local.text() == "":
            self.notify_box("Porta Local")
            return
        if not self.Servidor.listen(port=int(self.text_PORT_Local.text())):
            print("Falha ao iniciar o servidor")
            sys.exit()

        print("Servidor iniciado e aguardando conexões...")

    def handle_connection(self):
        try:
            self.client_socket = self.Servidor.nextPendingConnection()
            self.client_socket.readyRead.connect(
                lambda: self.receive_message(self.client_socket))
            self.client_socket.disconnected.connect(
                lambda: self.disconnect_client(self.client_socket))

        except:
            self.client_socket.readyRead.connect(
                lambda: self.receive_message(self.client_socket))
            self.client_socket.disconnected.connect(
                lambda: self.disconnect_client(self.client_socket))

        print("Novo cliente conectado:",
              self.client_socket.peerAddress().toString())

    def receive_message(self, client_socket):
        global flag_first_message, p_, alfa_, Yb_, Xa_
        message = client_socket.readAll().data()
        print("(" + str(flag_first_message)+")Mensagem recebida de",
              client_socket.peerAddress().toString(), ":", message)
        if (flag_first_message  and (self.opt_ALGORITHMS.currentText() == 'SDES + DH' or self.opt_ALGORITHMS.currentText() == 'RC4 + DH')):
            # primeira mensagme é a chave DH
            global Yb_
            Yb_ = int.from_bytes(message, 'big')
            print("Yb recebido:", Yb_)
            flag_first_message = False
        else:
            # Mensagem recebida, entao vai Decriptar
            print("Decriptando...")

            K = (Yb_**Xa_) % p_  # Chave compartilhada
            if self.opt_ALGORITHMS.currentText() == 'SDES + DH':
                K = (Yb_**Xa_) % p_  # Chave compartilhada
                print("(621)Chave: ", K)
                temp = ""
                for char in (str(K)):
                    temp += bin(ord(char)).replace("b", "")
                chave_ = temp[0:9]
                print("(626)Chave: ", K)

                if (len(chave_) < 10):
                    chave_ = "0"*(10-len(chave_)) + chave_
                print("Chave: ", chave_)
                self.text_KEY.setText(chave_)
            elif self.opt_ALGORITHMS.currentText() == 'RC4 + DH':
                chave_ = str(K)
                print("chave não-binaria", self.opt_ALGORITHMS.currentText())
                self.text_KEY.setText(chave_)
            else:
                None

            

            self.decripta_GLOBAL(self.text_KEY.text(), message, client_socket.peerAddress(
            ).toString(), self.opt_ALGORITHMS.currentText())

    def disconnect_client(self, client_socket):
        print("Cliente desconectado:", client_socket.peerAddress().toString())
        client_socket.deleteLater()

# CLIENTE
####################################
    def conectar(self):
        if self.text_IP.text() == "":
            self.notify_box("IP Destino.")
            return
        if self.text_PORT_Destino.text() == "":
            self.notify_box("Porta Destino")
            return
        self.Cliente.connectToHost(
            str(self.text_IP.text()), int(self.text_PORT_Destino.text()))

    def recebeMsg_Cliente(self):
        mensagem_ = self.Cliente.readAll().data()
        self.decripta_GLOBAL(self.text_KEY.text(), mensagem_, self.Cliente.peerAddres(
        ).toString(), self.opt_ALGORITHMS.currentText())

    def eventFilter(self, obj, event):
        if event.type() == QEvent.KeyPress and obj is self.text_MSG:
            if event.key() == Qt.Key_Return:
                self.enviar_mensagem(
                    'servidor', self.opt_ALGORITHMS.currentText())
                return True
            return False
          
        return False

    def updateTypeKEY(self):
        OPT = self.opt_ALGORITHMS.currentText()

        if OPT in ['SDES', 'ECB', 'CBC']:
            self.text_KEY.clear()
            self.text_KEY.setValidator(Validator("01"))
            self.text_KEY.setMaxLength(10)
            self.text_KEY.setReadOnly(False)

            self.text_MSG.clear()

        elif OPT == 'RC4':
            self.text_KEY.clear()
            self.text_KEY.setValidator(None)
            self.text_KEY.setMaxLength(256)
            self.text_KEY.setReadOnly(False)

            self.text_MSG.clear()
            self.text_MSG.setValidator(None)
            self.text_MSG.setMaxLength(256)

        elif OPT == 'RC4 + DH' or OPT == 'SDES + DH':
            self.text_KEY.clear()
            self.text_KEY.setReadOnly(True)
            global p_, alfa_, Xa_, Ya_
            if Xa_ == 0:
                Xa_ = randint(0, p_)  # Número secreto
                Ya_ = (alfa_**Xa_) % p_  # Número público
            else:
                None
            # envia Ya para o outro lado
            print("Xa: ", Xa_, " Ya: ", Ya_, " p: ", p_, " alfa: ", alfa_)
            self.Cliente.write(Ya_.to_bytes(2, byteorder='big'))

    def printaERRO(self, resultado):
        if resultado.returncode == 0:
            print("Compilação bem-sucedida.")
        else:
            print("Ocorreu um erro durante a compilação.")
            print("Saída de erro:", resultado.stderr)

    def get_local_ip(self):
        try:
            # Cria um socket para obter o IP local
            sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            # Conecta a um servidor externo (Google DNS)
            sock.connect(("8.8.8.8", 80))

            # Obtém o endereço IP local
            local_ip = sock.getsockname()[0]

            # Fecha o socket
            sock.close()

            return local_ip
        except socket.error:
            return None

    def compilaCodigos(self):
        comandos = [
            ['gcc', '-shared', '-o', 'sdes.so', '-fPIC', 'sdes.c']
            # ['gcc', '-shared', '-o', 'rc4.so', '-fPIC', 'rc4.c']
        ]
        paths = ['sdes/']  # , 'rc4/']

        for i in range(len(comandos)):
            original_path = os.getcwd()
            os.chdir(paths[i])
            resultado = subprocess.run(
                comandos[i], capture_output=True, text=True)
            self.printaERRO(resultado)
            os.chdir(original_path)

        try:
            self.so_des = "./sdes/sdes.so"
            self.sdes_functions = CDLL(self.so_des)

            # self.so_rc4 = "./rc4/rc4.so"
            # self.rc4_functions = CDLL(self.so_rc4)
            # self.rc4_functions.argtypes = [
            #     c_char_p,  # key
            #     c_char_p,  # plaintext
            #     ctypes.POINTER(ctypes.c_ubyte), # ciphertext
            #     ctypes.c_int
            # ]
            # self.rc4_functions.restype = None

        except:
            print("deu ruim padrin")
            None

    def decripta_GLOBAL(self, chave_, mensagem_cripto, cliente_ip, opt_algoritmo):
        global Yb_, flag_first_message

        if opt_algoritmo == 'SDES':
            try:
                mensagem_dcripto = ""

                for i in range(0, len(mensagem_cripto), 8):
                    buffer = create_string_buffer(8)
                    msg_slice = mensagem_cripto[i:i+8]
                    self.sdes_functions.dcript(
                        chave_.encode(), bytes(msg_slice), buffer)
                    mensagem_dcripto += chr(int(buffer.value.decode('latin-1'), 2))
                self.envia_mensagemCHAT(
                    mensagem_cripto.decode(), mensagem_dcripto, cliente_ip)
            except UnicodeDecodeError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False
            except ZeroDivisionError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False

            

        elif opt_algoritmo == 'RC4':
            print(chave_)
            try:
                mensagem_dcripto = RC4(chave_.encode(), mensagem_cripto).decode()
                self.envia_mensagemCHAT(
                    mensagem_cripto.hex(), mensagem_dcripto, cliente_ip)
            except UnicodeDecodeError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False
            except ZeroDivisionError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False

        elif opt_algoritmo == 'ECB':
            try:
                mensagem_dcripto = ""
                mensagem_blocada = self.divide_mensagem(mensagem_cripto, (8*8))
                for bloco in mensagem_blocada:
                    for binario in range(0, len(bloco), 8):
                        buffer = create_string_buffer(8)
                        msg_slice = bloco[binario:binario+8]

                        self.sdes_functions.dcript(
                            chave_.encode(), bytes(msg_slice), buffer)
                        mensagem_dcripto += chr(int(buffer.value.decode('latin-1'), 2))
                self.envia_mensagemCHAT(
                    mensagem_cripto.decode(), mensagem_dcripto, cliente_ip)
            except UnicodeDecodeError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False
            except ZeroDivisionError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False

        elif opt_algoritmo == 'CBC':
            try:
                mensagem_dcripto = ""
                mensagem_blocada = self.divide_mensagemCBC(mensagem_cripto, (8*8))
                IV = "00110010"
                IV = int(IV, base=2)
                i = 0
                for bloco in mensagem_blocada:
                    for binario in range(0, len(bloco), 8):
                        buffer = create_string_buffer(8)
                        msg_slice = bloco[binario:binario+8]

                        self.sdes_functions.dcript(
                            chave_.encode(), msg_slice.encode(), buffer)
                        if i == 0:
                            binXor = IV ^ int(
                                buffer.value.decode(), base=2)
                        else:
                            binXor =  int(buffer.value.decode(), base=2) ^ \
                            int(mensagem_blocada[i-1][binario:binario+8], base=2)
                        mensagem_dcripto += chr(binXor)
                    i += 1
                self.envia_mensagemCHAT(
                    mensagem_cripto.decode(), mensagem_dcripto, cliente_ip)
               
            except UnicodeDecodeError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False
            except ZeroDivisionError:
                Yb_ = int.from_bytes(mensagem_cripto, 'big')
                print("Yb recebido:", Yb_)
                flag_first_message = False


        elif opt_algoritmo == 'RC4 + DH':
            if chave_ == "":
                K = (Yb_**Xa_) % p_  # Chave compartilhada
                chave_ = str(K)
                print("Chave compartilhada: ", K)

                self.text_KEY.setText(chave_)
            print("(decriptando)Chave compartilhada: ", chave_)
            try:
                mensagem_dcripto = RC4(chave_.encode(),
                                    mensagem_cripto).decode()
                self.envia_mensagemCHAT(
                mensagem_cripto.hex(), mensagem_dcripto, cliente_ip)

            except UnicodeDecodeError:
                print("unicodedecodeerror)")
                K = (Yb_**Xa_) % p_  # Chave compartilhada
                chave_ = str(K)
                print("Chave compartilhada: ", K)
                self.text_KEY.setText(chave_)

            

        elif opt_algoritmo == 'SDES + DH':
            if chave_ == "":
                K = (Yb_**Xa_) % p_  # Chave compartilhada
                print("(621)Chave: ", K)
                temp = ""
                for char in (str(K)):
                    temp += bin(ord(char)).replace("b", "")
                chave_ = temp[0:9]
                print("(626)Chave: ", K)
                if (len(chave_) < 10):
                    chave_ = "0"*(10-len(chave_)) + chave_
                print("Chave: ", chave_)
                self.text_KEY.setText(chave_)
            mensagem_dcripto = ""
            # print(type(mensagem_cripto))
            # print(f'MsgCriptSDES Python -> {mensagem_cripto.decode()}\n')
            for i in range(0, len(mensagem_cripto), 8):
                buffer = create_string_buffer(8)
                msg_slice = mensagem_cripto[i:i+8]
                # print(msg_slice)
                try:
                    self.sdes_functions.dcript(chave_.encode(), bytes(msg_slice), buffer)
                    mensagem_dcripto += chr(int(buffer.value.decode('latin-1'), 2))
                except UnicodeDecodeError:
                    K = (Yb_**Xa_) % p_  # Chave compartilhada
                    chave_ = str(K)
                    print("Chave compartilhada: ", K)
                    self.text_KEY.setText(chave_)
            
            try:
                self.envia_mensagemCHAT(
                    mensagem_cripto.decode(), mensagem_dcripto, cliente_ip)
            except UnicodeDecodeError:
                None

    def envia_mensagemCHAT(self, mensagem_cripto, mensagem_dcripto, cliente_ip):
        R = randint(0, 255)
        G = randint(0, 255)
        B = randint(0, 255)

        if cliente_ip not in self.msgColors:
            self.msgColors[cliente_ip] = QColor(R, G, B)

        formato = QTextCharFormat()
        formato.setForeground(self.msgColors[cliente_ip])
        formato.setFontWeight(QFont.Bold)

        self.text_MSGCHAT.setCurrentCharFormat(formato)
        self.text_MSGCHAT.append(
            '<'+str(cliente_ip)+'>: ' + str(mensagem_dcripto))

        self.text_MSGCHAT_CRIPTO.setCurrentCharFormat(formato)
        self.text_MSGCHAT_CRIPTO.append(
            '<'+str(cliente_ip)+'>: ' + str(mensagem_cripto))

    def encripta_RC4(self, chave_, mensagem):
        tamMsg = len(mensagem)
        cifrado_ = (ctypes.c_ubyte * tamMsg)()
        self.rc4_functions.cript(
            chave_.encode(), mensagem.encode(), cifrado_, tamMsg)
        return bytes(cifrado_)

    def decripta_RC4(self, chave_, mensagem):
        cifrado_ = bytes.fromhex(mensagem)
        tamMsg = len(mensagem)
        decifrado_ = (ctypes.c_ubyte * tamMsg)()
        decifrado_ = self.rc4_functions.cript(
            chave_, cifrado_, decifrado_, tamMsg)
        decifrado_ = bytes(decifrado_)
        return decifrado_

    def divide_mensagemCBC(self, mensagem, tam, mensagem_blocadaCripto = []):
        divisao = []
        for i in range(0, len(mensagem), tam):
            divisao.append(str(mensagem[i:i+tam]).replace("b","").replace("'",""))
            mensagem_blocadaCripto.append([])
        return divisao
    
    def divide_mensagem(self, mensagem, tam, mensagem_blocadaCripto = []):
        divisao = []
        for i in range(0, len(mensagem), tam):
            divisao.append(mensagem[i:i+tam])
            mensagem_blocadaCripto.append([])
        return divisao

    def notify_box(self, campo):
        msg_notify = QMessageBox(self)
        msg_notify.setText("Preencha o(a) "+campo)
        msg_notify.exec()

    def enviar_mensagem(self, identidade, opt_Algoritmo):
        mensagem = str(self.text_MSG.text())
        chave_ = str(self.text_KEY.text())

        if mensagem == "":
            return

        if chave_ == "" and not (opt_Algoritmo == 'RC4 + DH' or opt_Algoritmo == 'SDES + DH'):
            self.notify_box("Chave de Criptografia")
            return

        if opt_Algoritmo == 'SDES':
            mensagem_cripto = ""
            buffer = [create_string_buffer(8) for i in range(
                len(mensagem))]  # buffer de 8 bits pra cada letra

            for i in range(len(mensagem)):
                letra = bin(ord(mensagem[i])).replace("b", "")
                if len(letra) < 8:
                    letra = "0"*(8-len(letra)) + letra
                self.sdes_functions.cript(
                    chave_.encode(), letra.encode('latin-1'), buffer[i])
                letra = str(bytes(buffer[i].value)).replace(
                    "b", "").replace("'", "")
                mensagem_cripto += letra

            temp = ""
            for i in range(len(buffer)):
                temp += str(buffer[i].value.decode())

            self.envia_mensagemCHAT(temp, mensagem, self.local_IP.text())

        elif opt_Algoritmo == 'RC4':
            mensagem_cripto = RC4(chave_.encode(), mensagem.encode())
            self.envia_mensagemCHAT(
                mensagem_cripto.hex(), mensagem, self.local_IP.text())

        elif opt_Algoritmo == 'ECB':
            mensagem_cripto = ""
            buffer = [create_string_buffer(8) for i in range(len(mensagem))]
            mensagem_blocada = self.divide_mensagem(mensagem, 8)
            i = 0
            for bloco in mensagem_blocada:
                for letra in bloco:
                    letraI = bin(ord(letra)).replace("b", "")
                    if len(letraI) < 8:
                        letraI = "0"*(8-len(letraI)) + letraI
                    self.sdes_functions.cript(
                        chave_.encode(), letraI.encode('latin-1'), buffer[i])
                    letraI = str(bytes(buffer[i].value)).replace(
                        "b", "").replace("'", "")
                    mensagem_cripto += letraI
                    i += 1
            temp = ""
            for i in range(len(buffer)):
                temp += str(buffer[i].value.decode())

            self.envia_mensagemCHAT(temp, mensagem, self.local_IP.text())

        elif opt_Algoritmo == 'CBC':
            mensagem_cripto = ""
            IV = "00110010"
            IV = int(IV, base=2)
            buffer = [create_string_buffer(8) for i in range(len(mensagem))]
            self.mensagem_blocadaCripto = []
            mensagem_blocada = self.divide_mensagem(mensagem, 8,self.mensagem_blocadaCripto)
            i = 0
            for bloco in range(len(mensagem_blocada)):
                for letra in range(len(mensagem_blocada[bloco])):
                    letraBin = bin(
                        ord(mensagem_blocada[bloco][letra])).replace("b", "")
                    if len(letraBin) < 8:
                        letraBin = "0"*(8-len(letraBin)) + letraBin

                    letraBin = int(letraBin, base=2)
                    if bloco == 0:
                        letraBin = letraBin ^ IV

                    else:
                        letraBinAnterior = self.mensagem_blocadaCripto[bloco-1][letra]
                        if len(letraBinAnterior) < 8:
                            letraBinAnterior = "0" * \
                                (8-len(letraBinAnterior)) + letraBinAnterior
                        letraBinAnterior = int(letraBinAnterior, base=2)

                        letraBin = letraBin ^ letraBinAnterior

                    letraBin = bin(letraBin).replace("b", "")
                    if len(letraBin) < 8:
                        letraBin = "0"*(8-len(letraBin)) + letraBin
                    
                    elif len(letraBin) > 8:
                        letraBin = letraBin[1:]

                    self.sdes_functions.cript(
                        chave_.encode(), letraBin.encode(), buffer[i])
                    letraBin = str(bytes(buffer[i].value)).replace(
                        "b", "").replace("'", "")
                    self.mensagem_blocadaCripto[bloco].append(letraBin)
                    mensagem_cripto += letraBin
                    i += 1

            temp = ""
            for i in range(len(buffer)):
                temp += str(buffer[i].value.decode())

            self.envia_mensagemCHAT(temp, mensagem, self.local_IP.text())

        elif opt_Algoritmo == 'RC4 + DH':
            if chave_ == "":
                K = (Yb_**Xa_) % p_  # Chave compartilhada
                chave_ = str(K)
                print("Chave compartilhada: ", K)

                self.text_KEY.setText(chave_)
            print("Chave: ", chave_)
            mensagem_cripto = RC4(chave_.encode(), mensagem.encode())
            self.envia_mensagemCHAT(
                mensagem_cripto.hex(), mensagem, self.local_IP.text())

        elif opt_Algoritmo == 'SDES + DH':
            if chave_ == "":
                K = (Yb_**Xa_) % p_  # Chave compartilhada
                print("(621)Chave: ", K)
                temp = ""
                for char in (str(K)):
                    temp += bin(ord(char)).replace("b", "")
                chave_ = temp[0:9]
                print("(626)Chave: ", K)
                if (len(chave_) < 10):
                    chave_ = "0"*(10-len(chave_)) + chave_
                print("Chave: ", chave_)
                self.text_KEY.setText(chave_)
            mensagem_cripto = ""
            buffer = [create_string_buffer(8) for i in range(
                len(mensagem))]  # buffer de 8 bits pra cada letra

            for i in range(len(mensagem)):
                letra = bin(ord(mensagem[i])).replace("b", "")
                if len(letra) < 8:
                    letra = "0"*(8-len(letra)) + letra
                self.sdes_functions.cript(
                    chave_.encode(), letra.encode('latin-1'), buffer[i])
                letra = str(bytes(buffer[i].value)).replace(
                    "b", "").replace("'", "")
                mensagem_cripto += letra
            self.envia_mensagemCHAT(
                mensagem_cripto, mensagem, self.local_IP.text())
        try:
            self.Cliente.write(mensagem_cripto.encode('latin-1'))
        except:
            self.Cliente.write(mensagem_cripto)
        self.text_MSG.clear()

    def get_instancia(cls):
        if not cls.__instancia__:
            cls.__instancia__ = super().get_instancia(cls)
        return cls.__instancia__


if __name__ == '__main__':
    app = QApplication(sys.argv)
    janela = mainWindow()
    janela.show()
    sys.exit(app.exec_())
