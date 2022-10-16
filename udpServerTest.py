# TCP
import socket

HOST = '127.0.0.1'
PORT = 16001

#소켓 생성
s = socket.socket(socket.AF_INET,    #Internet
socket.SOCK_STREAM)  #TCP

# 소켓 받을 주소 설정
s.bind((HOST, PORT))

# 서버 수용 기기 수 설정
s.listen(1)     #1명만 접속 가능

# 
conn, addr = s.accept()    
print('Connected by', addr)

while 1 :
    # 패킷 받기
    data = conn.recv(1024)
    if not data:
        break

    # 패킷 출력
    print(data.decode())

    # 패킷 회신
    conn.sendall(data)


# 패킷 닫기
conn.close()


# UDP는 TCP에는 없는 conn이 있어서 서버가 클라에게 다시 보낼때 conn을 통해 주소 없이 보낼 수 있다


# UDP
import socket

UDP_IP = '127.0.0.1'
UDP_PORT = 16002

#소켓 생성
s = socket.socket(socket.AF_INET,    #Internet
socket.SOCK_DGRAM)  #TCP

# 소켓 받을 주소 설정
s.bind((UDP_IP, UDP_PORT))

# 
while True:
    # 패킷 받기
    data, addr = s.recvfrom(1024) 
    
    # 패킷 출력
    print(data.decode())

    # 패킷 회신
    s.sendto(data, addr)

