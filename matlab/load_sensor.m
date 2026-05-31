%NI MAX Daq data export
close all
clear all
clc
d = daqlist("ni")
deviceInfo = d{1, "DeviceInfo"}
dq = daq("ni");
dq.Rate = 500;
time=30;
%zero_input=0.030354;
calibration_constant=44.4697 %N/mV 41.9783;

%  addinput(dq, "Dev2", "ai0", "Voltage");
%  addinput(dq, "Dev2", "ai1", "Voltage");
%  addinput(dq, "Dev2", "ai2", "Voltage");
%  addinput(dq, "Dev2", "ai3", "Voltage");
% addinput(dq, "Dev2", "ai4", "Voltage");
addinput(dq, "Dev2", "ai5", "Voltage");
%addinput(dq, "Dev2", "ai6", "Voltage");
%addinput(dq, "Dev2", "ai7", "Voltage");

disp('READY')

tabledata = read(dq)
data = read(dq,seconds(time));
data1 = data{:,:};
data1=(data1-data1(1))*calibration_constant;

plot(linspace(0,time,dq.Rate*time),smooth(data1));
title('F(t)')
xlabel('Time(s)')
ylabel('Force(N)')