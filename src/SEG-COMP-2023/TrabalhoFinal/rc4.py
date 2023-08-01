def permutaInicial(chave_):
    tamK = len(chave_)
    S = list(range(256))
    j = 0
    for i in range(256):
        j = (j + S[i] + chave_[i % tamK]) % 256 
        S[i], S[j] = S[j], S[i] #swap
    return S

def cifraMSG(S, mensagem_, cifrado_):
    tamMsg = len(mensagem_)
    i = j = 0

    for l in range(tamMsg):
        i = (i + 1) % 256
        j = (j + S[i]) % 256
        S[i], S[j] = S[j], S[i]
        t = (S[i] + S[j]) % 256
        k = S[t]
        cifrado_.append(mensagem_[l]^k)
        l+=1

def RC4(key_, mensagem_):
    S = permutaInicial(key_)

    cifrado_ = []
    cifraMSG(S, mensagem_, cifrado_)
    return bytes(cifrado_)


    