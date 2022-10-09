#include <iostream>
#include <vector>
using namespace std;

// banyak vertex pada graph
class Graph {
    private:
        // menyimpan banyak vertex dan adj matrix
        int numVertex;
        vector<vector<int>> adjMatrix;
        // fungsi unguk menginisialisasi adjacency matrixs
        vector<vector<int>> initializeMatrix(int numVertex) {
            return vector<vector<int>>(numVertex, vector<int>(numVertex, 0));
        }
        // fungsi untuk mengecek apakah vertex berada pada graph atau tidak
        bool isValid(int vertex) {
            return (0 <= vertex && vertex <= numVertex);
        }
    public:
        // constructor untuk mengisi nilai private variable
        Graph(int numVertex) {
            this->numVertex = numVertex;
            this->adjMatrix = initializeMatrix(numVertex);
        }

        // fungsi untuk menambah x vertex ke graph
        void addVertex(int count = 1) {
            numVertex += count; 
            int prevSize = adjMatrix.size();
            for(int i = 0; i < prevSize; i++) {
                for(int j = 0; j < count; j++) {
                    adjMatrix.push_back(vector<int>(numVertex, 0));
                    adjMatrix[i].push_back(0);
                }
            }    
        }

        // fungsi untuk mengurangi vertex x dari graph
        void removeVertex(int vertexPosition) {
            if(!isValid(vertexPosition)) {
                cout << "input tidak valid\n";
            }

            adjMatrix.erase(adjMatrix.begin() + vertexPosition);
        }

        // fungsi untuk menambah hubungan antar vertex
        void addEdge(int srcVertex, int dstVertex) {
            if(!isValid(srcVertex) && !isValid(dstVertex)) {
                cout << "input tidak valid\n";
            }
               
            adjMatrix[srcVertex][dstVertex] = 1;
        }

        // fungsi untuk menghapus hubungan antar vertex
        void removeEdge(int srcVertex, int dstVertex) {
            if(!isValid(srcVertex) && !isValid(dstVertex)) {
                cout << "input tidak valid\n";
            }

            adjMatrix[srcVertex][dstVertex] = 0;
        }

        // fungsi untuk mengecek hubungan antara 2 vertex
        int query(int srcVertex, int dstVertex) {
            if(!isValid(srcVertex) && !isValid(dstVertex)) {
                cout << "input tidak valid\n";
            }

            return adjMatrix[srcVertex][dstVertex];
        }

        // fungsi untuk mem-print graph
        void printGraph() {
            for (int i = 0; i < adjMatrix.size(); i++) {
                cout << i << " --> ";
                for (int j = 0; j < adjMatrix[i].size(); j++) {
                    cout << adjMatrix[i][j] << " ";
                }    
                cout << endl;
            }
        }

};

int main() {
    printf("Graph awal\n");
    Graph myGraph = Graph(5);
    myGraph.printGraph();
    printf("\n");

    printf("Graph setelah menghubungkan vertex 3 dengan vertex lainnya\n");
    myGraph.addEdge(3, 0);
    myGraph.addEdge(3, 1);
    myGraph.addEdge(3, 2);
    myGraph.addEdge(3, 3);
    myGraph.addEdge(3, 4);
    myGraph.printGraph();
    printf("\n");

    printf("Graph setelah menghapus vertex 3\n");
    myGraph.removeVertex(3);
    myGraph.printGraph();
    printf("\n");
    return 0;
}