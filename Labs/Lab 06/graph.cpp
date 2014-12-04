#include "graph.h"
using namespace std;

// default constructor at work here; pretty cute!
graph::graph(){
	
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
	string line;
	string city_name;
	int lat1, lat2, long1, long2;
	ifstream file_to_read;
	char compass_dir;

	// open the data file of cities
	open_for_read(file_to_read, filename);


  while(is_more_stuff_there(file_to_read)){
    //read in a line, process that city
    //add that vertex
  }

	// now we are done with our file
	file_to_read.close();

  //add the edges
  for(unsigned int i = 0; i < g.vertices.size(); i++){
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




