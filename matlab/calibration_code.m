%NI MAX Daq data export
close all
clear all
clc
d = daqlist("ni")
deviceInfo = d{1, "DeviceInfo"}
dq = daq("ni");
dq.Rate = 5000;
time=5;
voltage_vector=zeros([6,1]);
force_vector=zeros([6,1]);

g=9.807; %m/s^2 in Ankara !

%addinput(dq, "Dev2", "ai0", "Voltage");
%addinput(dq, "Dev2", "ai1", "Voltage");
%addinput(dq, "Dev2", "ai2", "Voltage");
%addinput(dq, "Dev2", "ai3", "Voltage");
%addinput(dq, "Dev2", "ai4", "Voltage");
addinput(dq, "Dev2", "ai5", "Voltage");
%addinput(dq, "Dev2", "ai6", "Voltage");
%addinput(dq, "Dev2", "ai7", "Voltage");

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inserted_mass = input('Mass Placed (kg):')

disp('READY')
tabledata = read(dq)
data = read(dq,seconds(time));
data_0 = data{:,:};
mean_data_0=mean(data_0);
force=inserted_mass*g;

force_vector(1)=force;
voltage_vector(1)=mean_data_0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inserted_mass = input('Mass Placed (kg):')

disp('READY')
tabledata = read(dq)
data = read(dq,seconds(time));
data_0 = data{:,:};
mean_data_0=mean(data_0);
force=inserted_mass*g;

force_vector(2)=force;
voltage_vector(2)=mean_data_0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inserted_mass = input('Mass Placed (kg):')

disp('READY')
tabledata = read(dq)
data = read(dq,seconds(time));
data_0 = data{:,:};
mean_data_0=mean(data_0);
force=inserted_mass*g;

force_vector(3)=force;
voltage_vector(3)=mean_data_0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inserted_mass = input('Mass Placed (kg):')

disp('READY')
tabledata = read(dq)
data = read(dq,seconds(time));
data_0 = data{:,:};
mean_data_0=mean(data_0);
force=inserted_mass*g;

force_vector(4)=force;
voltage_vector(4)=mean_data_0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inserted_mass = input('Mass Placed (kg):')

disp('READY')
tabledata = read(dq)
data = read(dq,seconds(time));
data_0 = data{:,:};
mean_data_0=mean(data_0);
force=inserted_mass*g;

force_vector(5)=force;
voltage_vector(5)=mean_data_0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inserted_mass = input('Mass Placed (kg):')

disp('READY')
tabledata = read(dq)
data = read(dq,seconds(time));
data_0 = data{:,:};
mean_data_0=mean(data_0);
force=inserted_mass*g;

force_vector(6)=force;
voltage_vector(6)=mean_data_0;

voltage_vector=voltage_vector-voltage_vector(1);

calibration_vector=force_vector./voltage_vector; % [] mV/N
calibration_constant=mean(calibration_vector(2:size(calibration_vector,1))); %mV/N





