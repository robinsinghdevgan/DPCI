#include <iostream>
#include <iomanip> //setw
#include <vector>
#include <map>
using std::cout;
using std::endl;
using std::map;
using std::setw;
using std::vector;

typedef std::string coordinates;
map<coordinates, int> coordinates_to_access_count;


void print_map()
{
    for (auto p : coordinates_to_access_count)
    {
        cout << p.first << " : " << p.second << endl;
    }
}

void print_vector_of_vector(const vector<vector<int>> &arr)
{
    for (auto v : arr)
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
}


//top-down approach, not memory efficient
void helper(vector<vector<int>> &arr, const int &n, int i, int j)
{
    if (i < 0 or j < 0)
        return;
    ++coordinates_to_access_count[std::string("(" + std::to_string(i) + ", " + std::to_string(j) + ")")];
    if ((i == n - 1 and j != n - 1) or (i != n - 1 and j == n - 1))
        arr[i][j] = 1;
    else
    {
        int south_value = 0, east_value = 0;
        if (i + 1 < n)
            south_value = arr[i + 1][j];
        if (j + 1 < n)
            east_value = arr[i][j + 1];

        arr[i][j] = std::max(south_value + east_value, arr[i][j]);
    }
    helper(arr, n, i - 1, j);
    helper(arr, n, i, j - 1);
}

int number_of_ways_top_down(int sizeOfMatrix)
{
    int &n = sizeOfMatrix;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int i = n - 1, j = n - 1;
    arr[i][j] = 0; //already at the bottom right end of the matrix
    helper(arr, n, i, j);
    print_vector_of_vector(arr);
    return arr[0][0];
}


int ComputeNumberOfWaysToIJ(int i, int j,
                            vector<vector<int>> *number_of_ways_ptr)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    ++coordinates_to_access_count[std::string("(" + std::to_string(i) + ", " + std::to_string(j) + ")")];

    vector<vector<int>> &number_of_ways = *number_of_ways_ptr;
    if (number_of_ways[i][j] == 0)
    {
        int ways_top =
            i == 0 ? 0 : ComputeNumberOfWaysToIJ(i - 1, j, number_of_ways_ptr);
        int ways_left =
            j == 0 ? 0 : ComputeNumberOfWaysToIJ(i, j - 1, number_of_ways_ptr);
        number_of_ways[i][j] = ways_top + ways_left;
    }
    return number_of_ways[i][j];
}

//bottom-up approach, maximum of 2 calls per block
int NumberOfWays(int n)
{
    vector<vector<int>> number_of_ways(n, vector<int>(n, 0));
    int res = ComputeNumberOfWaysToIJ(n - 1, n - 1, &number_of_ways);
    print_vector_of_vector(number_of_ways);
    return res;
}

int main(int argc, char const *argv[])
{
    cout << setw(10);
    /*cout << "\n\n"
         << number_of_ways(2);
    cout << "\n\n"
         << number_of_ways(3);
         */
    cout << "\n\n"
         << NumberOfWays(4) << endl;
    print_map();
    coordinates_to_access_count.clear();
    cout << "\n\n"
         << number_of_ways_top_down(4) << endl;
    print_map();
    return 0;
}
