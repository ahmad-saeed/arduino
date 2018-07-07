function varargout = seminarskiArduinoNP(varargin)
% SEMINARSKIARDUINONP M-file for seminarskiArduinoNP.fig
%      SEMINARSKIARDUINONP, by itself, creates a new SEMINARSKIARDUINONP or raises the existing
%      singleton*.
%
%      H = SEMINARSKIARDUINONP returns the handle to a new SEMINARSKIARDUINONP or the handle to
%      the existing singleton*.
%
%      SEMINARSKIARDUINONP('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SEMINARSKIARDUINONP.M with the given input arguments.
%
%      SEMINARSKIARDUINONP('Property','Value',...) creates a new SEMINARSKIARDUINONP or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before seminarskiArduinoNP_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to seminarskiArduinoNP_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help seminarskiArduinoNP

% Last Modified by GUIDE v2.5 05-Feb-2014 15:25:20

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @seminarskiArduinoNP_OpeningFcn, ...
                   'gui_OutputFcn',  @seminarskiArduinoNP_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before seminarskiArduinoNP is made visible.
function seminarskiArduinoNP_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to seminarskiArduinoNP (see VARARGIN)

% Choose default command line output for seminarskiArduinoNP

handles.output = hObject;
  set(handles.slider1,'Value',90);
  axes(handles.axes1);
  set(handles.axes1,'XTick',[])
  set(handles.axes1,'YTick',[])
  axis square;
  x=[8 12 12 8];
  y=[1 1 8 8];
  patch(x,y,([0.8 0.8 0.8]))
  hold on
  x1=[8.5 11.5 11.5 8.5];
  y1=[4.5 4.5 7.5 7.5];
  patch(x1,y1,([0.8 0.8 0.8]))
  hold on
  %{ 
  numPoints=200;  
  theta=linspace(0,2*pi,numPoints);
  radius=0.5;
  rho=ones(1,numPoints)*radius;
  [X,Y] = pol2cart(theta,rho);
  patch(X+1,Y+3,1)
  %}
  
  handles.ugao = 90;
  lijevo = handles.ugao + 90;
  desno = handles.ugao - 90;
  x11 = 0.5*cosd(lijevo)+10;
  y11 = 0.5*sind(lijevo)+6;
  x12 = 0.5*cosd(desno)+10;
  y12 = 0.5*sind(desno)+6;
  x13 = 4*cosd(handles.ugao)+10;
  y13 = 4*sind(handles.ugao)+6;
  x2=[x11 x12 x13];
  y2=[y11 y12 y13];
  patch(x2,y2,'r')
  t = linspace(0,2*pi,1000);
  h=10;
  k=6;
  r=0.5;
  X = r*cos(t)+h;                   
  Y = r*sin(t)+k;
  patch(X,Y,'r')
% Update handles structure

guidata(hObject, handles);
% UIWAIT makes seminarskiArduinoNP wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = seminarskiArduinoNP_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on slider movement.
function slider1_Callback(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of
%        slider

% --- Executes during object creation, after setting all properties.
function slider1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called



% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)

% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

global gl
if isempty(gl)
      gl = 90;
end
arduino = serial('COM2','BaudRate',9600);  
fopen(arduino);
try 
while true
pause(1);
bro = 0;
clear bro;
tekst = '';
clear tekst;
granica = '';
dopunska = '';
vrijednost = get(handles.slider1,'Value'); 
vrijednostINT = int64(vrijednost);
tekst = num2str(vrijednostINT);
bro = 180 - str2num(tekst);
set(handles.text1,'String',num2str(bro));
if bro < 100 && bro > 9
   clear tekst;
   if gl < 100 && gl > 10
      granica = strcat('0',num2str(gl));
   end
   if gl > 99
      granica = num2str(gl);
   end
   if gl < 10
      granica = strcat('00',num2str(gl));
   end
   dopunska = strcat('0',num2str(bro));
   tekst = strcat(dopunska,granica);
   fprintf(arduino, '%s', tekst);
   fukcijaRotiranja(gl,bro);
end

if bro > 99
      clear tekst;
   if gl < 100 && gl> 10
      granica = strcat('0',num2str(gl));
   end
   if gl > 99
      granica = num2str(gl);
   end
   if gl < 10
      granica = strcat('00',num2str(gl));
   end
   dopunska = num2str(bro);
   tekst = strcat(dopunska,granica);
   fprintf(arduino, '%s', tekst);
   fukcijaRotiranja(gl,bro);
end

if bro < 10
   clear tekst;
   if gl < 100 && gl> 10
      granica = strcat('0',num2str(gl));
   end
   if gl > 99
      granica = num2str(gl);
   end
   if gl < 10
      granica = strcat('00',num2str(gl));
   end
   dopunska = strcat('00',num2str(bro));
   tekst = strcat(dopunska,granica);
   fprintf(arduino, '%s', tekst);
   fukcijaRotiranja(gl,bro);
end

gl = bro;
end
catch err
    fclose(arduino);
    clear all 
    return;
end

function figure1_CloseRequestFcn(hObject, eventdata, handles)
clear all;
close all;
delete(hObject);
    



% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
clear all;
close all;

function [] = fukcijaRotiranja(od,do)
if od < do   
   for i = od : 1 : do
   cla;
   x=[8 12 12 8];
   y=[1 1 8 8];
   patch(x,y,([0.8 0.8 0.8]))
   hold on
   x1=[8.5 11.5 11.5 8.5];
   y1=[4.5 4.5 7.5 7.5];
   patch(x1,y1,([0.8 0.8 0.8]))
   hold on
   lijevo = i + 90;
   desno = i - 90;
   x11 = 0.5*cosd(lijevo)+10;
   y11 = 0.5*sind(lijevo)+6;
   x12 = 0.5*cosd(desno)+10;
   y12 = 0.5*sind(desno)+6;
   x13 = 4*cosd(i)+10;
    y13 = 4*sind(i)+6;
    x2=[x11 x12 x13];
    y2=[y11 y12 y13];
    h = patch(x2,y2,'r');
    zdir = [0 0 1];
    centar = [10 6 0];
    rotate(h, zdir, 1, centar);
    t = linspace(0,2*pi,1000);
    h=10;
    k=6;
    r=0.5;
    X = r*cos(t)+h;                   
    Y = r*sin(t)+k;
    patch(X,Y,'r')
    pause(0.00005);
    
    
   end
else
   for i = od : -1 : do
   cla;
   x=[8 12 12 8];
   y=[1 1 8 8];
   patch(x,y,([0.8 0.8 0.8]))
   hold on
   x1=[8.5 11.5 11.5 8.5];
   y1=[4.5 4.5 7.5 7.5];
   patch(x1,y1,([0.8 0.8 0.8]))
   hold on
   lijevo = i + 90;
   desno = i - 90;
   x11 = 0.5*cosd(lijevo)+10;
   y11 = 0.5*sind(lijevo)+6;
   x12 = 0.5*cosd(desno)+10;
   y12 = 0.5*sind(desno)+6;
   x13 = 4*cosd(i)+10;
    y13 = 4*sind(i)+6;
    x2=[x11 x12 x13];
    y2=[y11 y12 y13];
    h = patch(x2,y2,'r');
    zdir = [0 0 1];
    centar = [10 6 0];
    rotate(h, zdir, 1, centar);
    t = linspace(0,2*pi,1000);
    h=10;
    k=6;
    r=0.5;
    X = r*cos(t)+h;                   
    Y = r*sin(t)+k;
    patch(X,Y,'r')
    pause(0.00005);
   end
end
    
