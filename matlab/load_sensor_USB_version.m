%NI MAX Daq data export
close all
clear all
clc
delete(instrfindall)

d = daqlist("ni")
deviceInfo = d{1, "DeviceInfo"}
dq = daq("ni");
dq.Rate = 100;
time=10;
zero_input=0.025378;
calibration_constant=41.9783       %41.9783; %N/mV
sendData = 7;

  addinput(dq, "Dev1", "ai0", "Voltage");
%  addinput(dq, "Dev1", "ai1", "Voltage");
%  addinput(dq, "Dev1", "ai2", "Voltage");
%  addinput(dq, "Dev1", "ai3", "Voltage");


disp('READY')

arduinoCom = serial('COM10','BaudRate',9600);  % insert your serial
                                                           %properties here

fopen(arduinoCom);
fprintf(arduinoCom,'%f',sendData); %this will send 5 to the arduino
%this will read response
                       %or use BytesAvailableFcn property of serial
pause(0.6)
tabledata = read(dq)
data = read(dq,seconds(time));
data1 = data{:,:};
data1=(data1-data1(1))*calibration_constant;
%%
% plot(linspace(0,time,dq.Rate*time)/0.81,smooth(data1));
plot(linspace(0,time,dq.Rate*time)/0.8110,smooth(data1,20));
grid on
title('F(t)')
xlabel('mm')
ylabel('Force(N)')

fscanf(arduinoCom)

delete(instrfindall)
