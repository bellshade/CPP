#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// banyak vertex pada graph
class Graph {
    private:
        // menyimpan banyak vertex dan adj matrix
        int numVertex;
        vector<pair<int, vector<int>>> vertices;

        // fungsi untuk mengecek apakah vertex berada pada graph atau tidak
        bool isInGraph(int vertexName) {
            for(auto vertex : vertices) {
                if(vertex.first == vertexName) return true;
            }
            return false;
        }

        // fungsi untuk mencari posisi vertex pada vertices
        int findInGraph(int vertexName) {
            for(int i = 0; i < vertices.size(); i++) {
                if(vertices[i].first == vertexName) return i;
            }
            return -1;
        }
    public:
        // constructor untuk menginisialisasi private variable;
        Graph() {
            this->numVertex = 0;
        }

        // fungsi untuk menambah x vertex ke graph
        void addVertex(int vertexName) {
            if(isInGraph(vertexName)) {
                cout << "vertex sudah ada dalam graph";
                return;
            }

            numVertex++;     

            // menambah relasi untuk vertex baru
            for(auto & vertex : vertices) {
                vertex.second.push_back(0);
            }


            // menambah vertex baru
            pair<int, vector<int>> vertex;
            vertex.first = vertexName;
            for(int i = 0; i < numVertex; i++) {
                vertex.second.push_back(0);
            }
            vertices.push_back(vertex);
        }

        // fungsi untuk mengurangi vertex x dari graph
        void removeVertex(int vertexName) {
            if(!isInGraph(vertexName)) {
                cout << "vertex tidak ada dalam graph\n";
                return;
            }

            // menghapus vertex
            int pos = findInGraph(vertexName);
            vector<pair<int, vector<int>>>::iterator vtxIt = vertices.begin() + pos;
            vertices.erase(vtxIt);

            // menghapus relasi vertex
            for(auto & vertex : vertices) {
                vector<int>::iterator elemIt = vertex.second.begin() + pos;
                vertex.second.erase(elemIt);
            }
        }

        // fungsi untuk menambah hubungan antar vertex
        void addEdge(int srcVertexName, int dstVertexName) {
            if(!isInGraph(srcVertexName) && !isInGraph(dstVertexName)) {
                cout << "vertex tidak ada dalam graph\n";
            }
               
            int srcIndex = findInGraph(srcVertexName);
            int dstIndex = findInGraph(dstVertexName);
            vertices[srcIndex].second[dstIndex] = 1;
        }

        // fungsi untuk menghapus hubungan antar vertex
        void removeEdge(int srcVertexName, int dstVertexName) {
            if(!isInGraph(srcVertexName) && !isInGraph(dstVertexName)) {
                cout << "vertex tidak ada dalam graph\n";
            }

            int srcIndex = findInGraph(srcVertexName);
            int dstIndex = findInGraph(dstVertexName);
            vertices[srcIndex].second[dstIndex] = 0;
        }

        // fungsi untuk mengecek hubungan antara 2 vertex
        int query(int srcVertexName, int dstVertexName) {
            if(!isInGraph(srcVertexName) && !isInGraph(dstVertexName)) {
                cout << "vertex tidak ada dalam graph\n";
            }

            int srcIndex = findInGraph(srcVertexName);
            int dstIndex = findInGraph(dstVertexName);
            return vertices[srcIndex].second[dstIndex];
        }

        // fungsi untuk mem-print graph
        void printGraph() {
            for(auto vertex : vertices) {
                cout << vertex.first << " --> ";
                for(auto elem : vertex.second) {
                    cout << elem << " ";
                }  

                cout << "\n";
            }
        }

};

int main() {
    printf("Graph awal\n");
    Graph myGraph = Graph();
    myGraph.addVertex(1);
    myGraph.addVertex(2);
    myGraph.addVertex(3);
    myGraph.addVertex(4);
    myGraph.addVertex(5);
    myGraph.printGraph();
    cout << endl;

    printf("Graph setelah menghubungkan vertex 3 dengan vertex lainnya\n");
    myGraph.addEdge(3,1);
    myGraph.addEdge(3,2);
    myGraph.addEdge(3,3);
    myGraph.addEdge(3,4);
    myGraph.addEdge(3,5);
    myGraph.printGraph();
    cout << endl;

    printf("Graph setelah menghapus vertex 3\n");
    myGraph.removeVertex(3);
    myGraph.printGraph();
    return 0;
}
