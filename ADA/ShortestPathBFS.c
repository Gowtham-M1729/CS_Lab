#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n, m = 0;
int adj[MAX][MAX]; //adjacency matrix, where adj[i][j] = 1, denotes there is an  edge from i to j
int visited[MAX];  //visited[i] can be 0 or 1, 0 : it has not yet printed, 1 : it has been printed
int track[MAX];
void create_graph();
void BF_Traversal();
void BFS();

int queue[MAX], stack[MAX], track[MAX], front = -1, rear = -1, top = -1;
int track_size = 0, stack_size = 0;
void push_queue(int vertex);
int pop_queue();
int isEmpty_queue();
void push_track(int data);
void shortest_path();
void push(int p);
int pop();

int main()
{
    create_graph();  //Create a graph
    BFS();           //Traverse the graph in BFS keeping track of every node visited
    shortest_path(); //Print out the shortest path
    return 0;
}

void BFS()
{
    int v, src, des;

    for (v = 0; v < n; v++)
        visited[v] = 0;

    printf("Enter the source and destination nodes: ");
    scanf("%d%d", &src, &des);
    v = src;

    int i;

    push_queue(v); //A queue is for the normal bfs algorithm
    push_track(9); // this array is to track all the nodes visited

    while (!isEmpty_queue())
    {

        v = pop_queue();
        if(visited[v])
        continue;
        push_track(v);
        visited[v] = 1;

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1)
                push_track(i);
            if (adj[v][i] == 1 && i == des)
                return;
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                push_queue(i);
            }
        }
        push_track(9);//I used 9 as a separator after each node traversal, so the max vertices is 9(0-8) 
    }
    printf("\n");
}

void push_queue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int pop_queue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

void push(int p)
{
    top++;
    stack[top] = p;
    stack_size++;
}

int pop()
{
    return stack[top--];
}

void push_track(int data)
{
    track[m] = data;
    m++;
    track_size++;
}

void shortest_path()
{
    push(9); //using a stack for arranging the shortest path from the tracking array
    push(track[track_size - 1]);
    int a, i, j, first = 1;
    for (i = track_size - 1; i >= 0; i--)
    {
        if (track[i] == 9 && first == 1)
        {
            a = i + 1;
            push(track[a]);
            first = 0;
            continue;
        }
        if (track[i] == track[a])
        {
            for (j = i; j >= 0; j--)
            {
                if (track[j] == 9)
                {
                    a = j + 1;
                    push(track[a]);
                    i = i - (i - j);
                    break;
                }
            }
        }
    }
    for (i = 0; i < stack_size - 1; i++)
    {
        int q = pop();
        if (q == 9)
            break;
        printf("%d ", q);
    }
}

void create_graph()
{
    int count, max_edge, origin, destin;

    printf("Enter number of vertices : ");
    scanf("%d", &n);
    max_edge = n * (n - 1); //assuming each vertex has an edge with remaining (n-1) vertices

    for (count = 1; count <= max_edge; count++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ", count);
        scanf("%d %d", &origin, &destin);

        if ((origin == -1) && (destin == -1))
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1; // assuming it is a bi-directional graph, we are pushing the reverse edges too.
        }
    }
}
