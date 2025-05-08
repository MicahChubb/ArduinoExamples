# Data Logger Example

On top of what we did in class, I addapted the logger to:

* Incorporate commas so we can import it as a CSV for graph purposes
* Only have the data we need writing, i.e dropping off the word "Timestamp" and just having the date and time
* Added an example sensor read (solar cell) function to show how I would pass the data
* Left space for you to add more sensor data to the logger

The output of the data logger should look like below:

![TimeStamp Example](https://github.com/MicahChubb/ArduinoExamples/blob/main/logger/timeStampExample.png?raw=true)

You can see that we have the data in the format: 
```date,time,solarReading```
The commas are important as these will be used to divide the data into different spreadsheet cells

## Things you should adjust
* Add more sensor readings
* Adjust the timing of your write outs, you do not need to do it every 2 seconds, I think meaningful data would be like an hour apart
## Things to keep in mind
* Your text file's name should be a maximum of 8 characters long, I was having an issue with "timestamp.txt" it turns out, shortening the name of the file was the fix
* sprintf() where we format our string for the time and date does not natively support floats, to retain my float I just wrote them out separately, this is why the solar cell formatting is separate to the time and date and the extra comma after it
