#include <stdio.h>
const char* edge_checker(int a, int b)
 {
    int edges[][2] = 
    {
        {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6},
        {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 1}
    };
    int num_edges = 10;
    for (int i = 0; i < num_edges; i++)
     {
        if ((edges[i][0] == a && edges[i][1] == b) || (edges[i][0] == b && edges[i][1] == a))
        {
            return "Yes";
        }
    }
    return "No";
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s\n", edge_checker(a, b));
    return 0;
}

