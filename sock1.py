
import socket
from firebase.firebase import FirebaseApplication
from firebase.firebase import FirebaseAuthentication
import Model
import time

app = FirebaseApplication('https://fall-detect-bc0b4.firebaseio.com/', None)
s = socket.socket()
def addition(hr,systo,diasto,pred):
    result1 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Pulse',hr)
    result2 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Systolic',systo)
    result3 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Diastolic',diasto)
    result3 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Fall',pred)
    time.sleep(1)
    return
 
s.bind(('0.0.0.0', 8090 ))
s.listen(0)                 
while True:
 
    client, addr = s.accept()
 
    while True:
        content = client.recv(32).decode('utf-8')
 
        if len(content) ==0:
           break
 
        else:
            #print(content)
            
            hr,systo,dia=content.split(",")
            hr=int(hr)
            systo =int(systo)
            dia=int(dia)
            predicted =str(Model.pred(hr,systo,dia))
            print(predicted)
            predicted=int(predicted)
            addition(hr,systo,dia,predicted)
            client.send(str(predicted).encode())
            
 
print("Closing connection")
client.close()
=======
import socket
from firebase.firebase import FirebaseApplication
from firebase.firebase import FirebaseAuthentication
import Model
import time

app = FirebaseApplication('https://fall-detect-bc0b4.firebaseio.com/', None)
s = socket.socket()
def addition(hr,systo,diasto,pred):
    result1 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Pulse',hr)
    result2 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Systolic',systo)
    result3 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Diastolic',diasto)
    result3 = app.put('https://fall-detect-bc0b4.firebaseio.com/','Fall',pred)
    time.sleep(1)
    return
 
s.bind(('0.0.0.0', 8090 ))
s.listen(0)                 
while True:
 
    client, addr = s.accept()
 
    while True:
        content = client.recv(32).decode('utf-8')
 
        if len(content) ==0:
           break
 
        else:
            #print(content)
            
            hr,systo,dia=content.split(",")
            hr=int(hr)
            systo =int(systo)
            dia=int(dia)
            predicted =str(Model.pred(hr,systo,dia))
            print(predicted)
            predicted=int(predicted)
            addition(hr,systo,dia,predicted)
            client.send(str(predicted).encode())
            
 
print("Closing connection")
client.close()

