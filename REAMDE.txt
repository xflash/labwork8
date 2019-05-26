# Decription
You have two csv file to use:

* path.csv

Structure
idPath; lineName; idStation; hour; sequenceNumber;

* stations.csv

Structure

stationName; idStation



### Exo1
You will have to create a structure called "station" containing all info about stations (name and id).

### Exo2
You will have to read the stations.csv file and fill an array of stations (you have 40 stations) with it.

### Exo3
You will have to create a function taking as argument :
* one array of Stations
* one idStation

This function will return the string corresponding to this id.

### Exo4
 You will have to create a structure called "path" containing all info about paths (idPath, lineName, stationName, hour and sequenceNumber).

### Exo5
 You will have to create a structure called "linkedListPath" that will be a linked list of paths

### Exo6
 You will have to read the path.csv file and create the linkedListPath (you will have to use function from exo3 to fill the "stationName").

### Exo7
 You will have to search (in the file or in the linkedListPath) and display the nameStation of each Station of each line.

### Exo8
 You will have to count the number of subway for each line

### Exo9
 You will have to right a function taking as argument :
* one linkedListPath
* one lineName
* one hour

This function will display the previous and next station if the subway is between two station a this hour, or the station where the subway is.

If there is no subway at this time, just display a message.
