# #TCP
# import socket
# HOST = '127.0.0.1'
# PORT = 16001

# #소켓 생성
# s = socket.socket(socket.AF_INET,    #Internet
# socket.SOCK_STREAM   #TCP
# )

# #소켓 목적지 설정
# s.connect((HOST, PORT))

# # 소켓 보낼 데이터 입력, 전송
# s.sendall(('hello world').encode())

# #서버로부터 소켓 받기
# data = s.recv(1024)
# #소켓 닫기
# s.close()





#UDP
import socket
UDP_IP = '127.0.0.1'
UDP_PORT = 16002

#소켓 생성
s = socket.socket(socket.AF_INET,    #Internet
socket.SOCK_DGRAM   #UDP
)

#소켓 보낼 데이터 입력, 목적지 설정, 전송
s.sendto(('hello world').encode(), (UDP_IP, UDP_PORT))

#서버로부터 소켓 받기
data = s.recv(1024)

#소켓 닫기
s.close()


