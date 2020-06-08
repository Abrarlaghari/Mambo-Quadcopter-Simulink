qmatrix(1,1)= -96.555;  
qmatrix(1,2)= -91.555;
qmatrix(1,3)= -81.605;
qmatrix(1,4)= -65.254;
qmatrix(1,5)= -68.754;
qmatrix(1,6)= -45.008;
qmatrix(1,7)= -42.523;
qmatrix(1,8)= -58.523;
qmatrix(2,1)= -96.555;
qmatrix(2,2)= -91.555;
qmatrix(2,3)= -81.605;
qmatrix(2,4)= -55.503;
qmatrix(2,5)= -31.789;
qmatrix(2,6)= -40.254;
qmatrix(2,7)= -31.524;
qmatrix(2,8)= -83.001;

qmatrix(3,1)= -96.555;
qmatrix(3,2)= -67.296;
qmatrix(3,3)= -81.605;
qmatrix(3,4)= -55.503;
qmatrix(3,5)= -31.789;
qmatrix(3,6)= -40.254;
qmatrix(3,7)= -31.524;
qmatrix(3,8)= -83.001;

qmatrix(4,1)= -96.555;
qmatrix(4,2)= -67.296;
qmatrix(4,3)= -38.035;
qmatrix(4,4)= 0;
qmatrix(4,5)= -20.481;
qmatrix(4,6)= -49.74;
qmatrix(4,7)= -79.001;
qmatrix(4,8)= -102.408;

qmatrix(5,1)= -96.555;
qmatrix(5,2)= -67.296;
qmatrix(5,3)= -38.035;
qmatrix(5,4)= -14.84;
qmatrix(5,5)= -25.235;
qmatrix(5,6)= -54.495;
qmatrix(5,7)= -79.001;
qmatrix(5,8)= -102.408;

qmatrix(6,1)= -61.507;
qmatrix(6,2)= -51.557;
qmatrix(6,3)= -34.328;
qmatrix(6,4)= -27.828;
qmatrix(6,5)= -75.577;
qmatrix(6,6)= -85.527;
qmatrix(6,7)= -90.527;
qmatrix(6,8)= -102.408;
a=arduino('COM15');
pinMode(a,5,'input');
servoAttach(a,9);
action=[70 78 86 94 102 110];
while 1
    val=analogRead(a,5);
    i=best_action(val,qmatrix);
    servoWrite(a,9,action(i));
    tic
    while toc<=0.01
    end   
end