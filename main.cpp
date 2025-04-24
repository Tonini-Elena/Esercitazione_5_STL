#include <iostream>
#include "PolygonalMesh.hpp"
#include "Utils.hpp"
#include "UCDUtilities.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;


int main()
{
    PolygonalMesh mesh;

    if(!ImportMesh(mesh))
    {
        cerr << "file not found" << endl;
        return 1;
    }
   
    cout << "Mesh imported successfully" << endl;
   

    Gedim::UCDUtilities utilities;
    utilities.ExportPoints("./Cell0Ds.inp",
                            mesh.Cell0DCoordinates);
    utilities.ExportSegments("./Cell1Ds.inp",
                              mesh.Cell0DCoordinates,
                              mesh.Cell1DVertices);
                              
    if (!CheckEdgeLenghts(mesh))
    {
        cerr << "Error: at least one side has zero length" << endl;
        return 1;
    }
    
    cout << "Each edge has non-zero length" << endl;
   
    
    if (!CheckPolygonAreas(mesh))
    {
        cerr << "Error: At least one polygon has zero PolygonAreas" << endl;
        return 1;
    }
    
    cout << "Each polygon has a non-zero PolygonAreas" << endl;
    
    

return 0;

}