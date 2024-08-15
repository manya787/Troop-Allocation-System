import time
import os

NO_PARENT = -1
p = [0] * 9
region = ["Kyiv", "Dnipro", "Sumy", "Lyman", "Donbas", "Izyum", "Irpin", "Lviv", "Odesa"]

def print_path(current_vertex, parents):
    if current_vertex == NO_PARENT:
        return
    print_path(parents[current_vertex], parents)
    print(" -> " + region[current_vertex], end='')

def print_solution(start_vertex, distances, parents, n):
    n_vertices = len(distances)
    print("\n" + region[start_vertex] + " -> " + region[n] + "\t\t\t " + str(distances[n]) + "\t\t\t", end='')
    print_path(n, parents)

def dijkstra(adjacency_matrix, start_vertex):
    n_vertices = len(adjacency_matrix)
    shortest_distances = [float('inf')] * n_vertices
    added = [False] * n_vertices
    shortest_distances[start_vertex] = 0
    parents = [NO_PARENT] * n_vertices

    for _ in range(1, n_vertices):
        nearest_vertex = -1
        shortest_distance = float('inf')
        for vertex_index in range(n_vertices):
            if not added[vertex_index] and shortest_distances[vertex_index] < shortest_distance:
                nearest_vertex = vertex_index
                shortest_distance = shortest_distances[vertex_index]
        added[nearest_vertex] = True
        for vertex_index in range(n_vertices):
            edge_distance = adjacency_matrix[nearest_vertex][vertex_index]
            if edge_distance > 0 and ((shortest_distance + edge_distance) < shortest_distances[vertex_index]):
                parents[vertex_index] = nearest_vertex
                shortest_distances[vertex_index] = shortest_distance + edge_distance
    
    p[0] = 0
    for i in range(1, 9):
        print(f"\nIs {region[i]} in danger?\nPress 1 for yes and 0 for no.")
        p[i] = int(input())
        if p[i] != 0 and p[i] != 1:
            print("Wrong input")
            return
    
    print("Vertex\t\t\t\tTime (hrs.)\t\t\t    Path")
    f = 0
    for i in range(1, 9):
        if p[i] == 1:
            f = 1
            print_solution(start_vertex, shortest_distances, parents, i)
    
    if f == 0:
        print("\nNone\t\t\t\tNone\t\t\tNone\n\nNo area is in danger")

def max_value(a, b):
    return a if a > b else b

def print_knapsack(W, wt, val, n):
    K = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i - 1] <= w:
                K[i][w] = max_value(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]

    res = K[n][W]
    x = 0
    w = W
    for i in range(n, 0, -1):
        if res == K[i - 1][w]:
            continue
        else:
            print(f"{wt[i - 1]} soldiers to be deployed to {region[i-1]}")
            x += 1
            res -= val[i - 1]
            w -= wt[i - 1]
    
    if x == 0:
        print("NO SOLDIERS TO BE DEPLOYED")

def intro():
    str = " ALGORITHM AND PROBLEM SOLVING LAB "
    str2 = " MINI PROJECT  "
    print("\n\n\n\t\t\t\t\t--------------------------------------------")
    print("\t\t\t\t\t\t", end='')
    for ch in str:
        time.sleep(0.05)
        print(ch, end='')
    print("\n\t\t\t\t\t\t  ", end='')
    for ch in str2:
        time.sleep(0.1)
        print(ch, end='')
    print("\n\t\t\t\t\t--------------------------------------------")
    time.sleep(1)
    top = "\n\n\t\t\t\t\t TROOP REINFORCEMENT ALLOCATION SYSTEM (UKRAINE EDITION)\n\n "
    for ch in top:
        time.sleep(0.1)
        print(ch, end='')
    print("\n\t-------------------------------\n")

    crt = "\tCREATED & DEVELOPED BY : "
    for ch in crt:
        time.sleep(0.1)
        print(ch, end='')
    print("\n\t------------------------- \n")
    name_s = "MANYA GARG (9921103162)\n "
    for ch in name_s:
        time.sleep(0.1)
        print(ch, end='')
    time.sleep(1)
    input("Press Enter to continue...")
    os.system("cls")

def main():
    #intro()
    while True:
        adjacency_matrix = [
            [0, 4, 0, 0, 0, 0, 0, 8, 0],
            [4, 0, 8, 0, 0, 0, 0, 11, 0],
            [0, 8, 0, 7, 0, 4, 0, 0, 2],
            [0, 0, 7, 0, 9, 14, 0, 0, 0],
            [0, 0, 0, 9, 0, 10, 0, 0, 0],
            [0, 0, 4, 0, 10, 0, 2, 0, 0],
            [0, 0, 0, 14, 0, 2, 0, 1, 6],
            [8, 11, 0, 0, 0, 0, 1, 0, 7],
            [0, 0, 2, 0, 0, 0, 6, 7, 0]
        ]

        print("\n\nWHICH COMMAND TO ENTER")
        print("ENTER 1 FOR ROUTE OF MEDICAL SUPPLIES")
        print("ENTER 2 FOR TROOP ALLOCATION")
        print("ENTER 3 TO KNOW ABOUT THE PROGRAM")
        print("ENTER 4 TO EXIT")
        n = int(input())

        if n == 1:
            os.system("cls")
            dijkstra(adjacency_matrix, 0)
        elif n == 2:
            os.system("cls")
            f = 0
            b = [0] * 9
            b[0] = 0
            for i in range(1, 9):
                print(f"\nIs {region[i]} in danger?\nPress 1 for yes and 0 for no.")
                b[i] = int(input())
                if b[i] != 0 and b[i] != 1:
                    print("Wrong input")
                    break
            
            print("\n\nNumber of soldiers in Reserves present at the Basecamp (Kyiv)")
            W = int(input())
            s_our, s_opp, cas, amm, dist = 0, 0, 0, 0, 0
            wt = [0] * 9
            val = [0] * 9

            for i in range(1, 9):
                if b[i] == 1:
                    print(f"\n\n* Enter details for location {region[i]} *\n")
                    s_our = int(input(f"Enter head count of soldiers that are fit to fight in your army : "))
                    s_opp = int(input(f"Enter approximation of resistance faced in {region[i]} : "))
                    cas = int(input("Enter number of casualties : "))
                    amm = int(input("Enter amount of ammunition left in quintals : "))
                    dist = int(input(f"Enter distance of {region[i]} from base camp in kms : "))
                    print("\n\n")
                    wt[i] = (3 * s_opp) - s_our
                    val[i] = (10000 * s_our * amm) / (s_opp * cas * dist)
                    if wt[i] < 0:
                        print(f"0 soldiers to be deployed to {region[i]}")
                        val[i] = -1
                    f = 1
                else:
                    val[i] = -1

            if f == 1:
                a = len(val)
                print_knapsack(W, wt, val, a)
            else:
                print("\nNO AREA IS IN DANGER\n\n")
        elif n == 3:
            os.system("cls")
            print("When a nation is engaged in a war, there are several fronts where the battles are being fought.")
            print("In such conditions, casualties and injuries are bound to happen.")
            print("Shortage of resources at any front is possible.")
            print("In such a case, if an efficient transportation system is not employed, there can be a huge setback.")
            print("The purpose of this program is to implement Dijkstra's algorithm and Knapsack approach to provide")
            print("a fool-proof solution to the problem. This program is written by Manya Garg")
        elif n == 4:
            break
        else:
            print("Wrong input")

if __name__ == "__main__":
    main()
