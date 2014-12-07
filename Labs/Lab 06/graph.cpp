#include "graph.h"
#include <sstream>
using namespace std;

// default constructor at work here; pretty cute!
graph::graph(){
	//woohoo!
}

// destructor is easy, we just clear our vertex vector and our edge map
graph::~graph(){
	edges.clear();
	vertices.clear();	
}

// add a vertex to the graph by adding it to the vector
void graph::add_vertex(const vertex& v){
	(*this).vertices.push_back(v);
}

// add an edge to the graph as long as it's under the distance limit
void graph::add_edge(vertex* v, vertex* u, double limit){
	if(great_circle_distance(*v, *u) < limit){
		edges.at(v).push_back(u);
		edges.at(u).push_back(v);
	}
}

// compute distance from one lat/long to another as the crow fliesv
double graph::great_circle_distance(const vertex& v, const vertex& u) const{
	double PI = 3.1415926535897932;
	double lat1, lat2, long1, long2, dist;

	lat1 = ((double) v.get_latitude_degrees()) + (((double) v.get_latitude_minutes()) / 60.0);
	lat1 *= PI/180.0;
	long1 = ((double) v.get_longitude_degrees()) + (((double) v.get_longitude_minutes()) / 60.0);
	long1 *= PI/180.0;
	lat2 = ((double) u.get_latitude_degrees()) + (((double) u.get_latitude_minutes()) / 60.0);
	lat2 *= PI/180.0;
	long2 = ((double) u.get_longitude_degrees()) + (((double) u.get_longitude_minutes()) / 60.0);
	long2 *= PI/180.0;

	// from http://www.meridianworlddata.com/Distance-Calculation.asp
	// result in km
	dist = 6378.7 * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(long2 - long1)));

	return dist;
}

// read in 120 cities and their latitude/longitude
// cities within limit km of each other are connected by edges
void init_graph_from_file(graph& g, const string& filename, double limit){
	//variables for managing file / current line in file
	ifstream file_to_read;
	string line;
	
	//variables for managing city data
	string city_name;
	int lat1, lat2, long1, long2;
	unsigned int colonLoc;
	string lat1str, lat2str, long1str, long2str;
	char compass_dir;

	// open the data file of cities
	open_for_read(file_to_read, filename);


  //~ while(is_more_stuff_there(file_to_read)){
		getline(file_to_read, line);
		
		//read city name (data before ':')
		colonLoc = line.find(':');
		city_name = line.substr(0, colonLoc);
		
		//build istringstream from current line to break into tokens
		istringstream coords(line.substr(colonLoc + 2));
		
		//pull and store token for lattitude degrees
		getline(coords, lat1str, ' ');
		lat1 = stoi(lat1str, nullptr, 10);
		
		//...and lattitude minutes
		getline(coords, lat2str, ' ');
		lat2 = stoi(lat2str, nullptr, 10);
		
		//..and lattitude compass direction
		coords.get(compass_dir);
		
		//delimiter not used to read compass, so eat next space
		coords.get();
		
		//..modify lattitude degrees and minutes if below equator
		if(compass_dir == 'S'){
			lat1 *= -1;
			lat2 *= -1;
		}
		
		//pull and store token for longitude degrees
		getline(coords, long1str, ' ');
		long1 = stoi(long1str, nullptr, 10);
		
		//..and longitude minutes
		getline(coords, long2str, ' ');
		long2 = stoi(long2str, nullptr, 10);
		
		//..and longitude compass direction
		coords.get(compass_dir);
		
		//..modify longitude degrees and minutes if west of prime meridian
		if(compass_dir == 'W'){
			long1 *= -1;
			long2 *= -1;
		}
	
  //~ }

	// now we are done with our file
	file_to_read.close();

  //add the edges
  for(unsigned int i = 0; i < g.vertices.size(); i++){
		cout << g.vertices[i].get_city_name();
    for(unsigned int j = 0; j < g.vertices.size(); j++){
      if(i != j){                                       //ensure edge to self is not added
        g.add_edge(&g.vertices[i], &g.vertices[j], limit);
      }
    }
  }

}

// function defined by Michael Main for input data
void open_for_read(ifstream& f, string filename){
	f.open(filename);
	if (f.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(0);
	}
}

// function defined by Michael Main for input data
bool is_more_stuff_there(ifstream& f){
		return (f && (f.peek() != EOF));
}




