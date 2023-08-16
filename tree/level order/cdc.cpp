#include <bits/stdc++.h>
using namespace std;

const int MOD = 5557;

map<tuple<int, vector<int>, int>, int> memo;

int count_ways(map<int, vector<tuple<int, vector<int>, int>>> &graph, int time_left, int current_node, vector<int> &ingredients)
{
    if (time_left < 0)
    {
        return 0;
    }

    if (time_left == 0 && all_of(ingredients.begin(), ingredients.end(), [](int i)
                                 { return i == 1; }))
    {
        return 1;
    }

    if (memo.find(make_tuple(current_node, ingredients, time_left)) != memo.end())
    {
        return memo[make_tuple(current_node, ingredients, time_left)];
    }

    int ways = 0;
    for (auto &neighbor_data : graph[current_node])
    {
        int neighbor, travel_time;
        vector<int> shop_ingredients;
        tie(neighbor, shop_ingredients, travel_time) = neighbor_data;

        vector<int> new_ingredients = ingredients;
        for (int i = 0; i < 4; ++i)
        {
            if (shop_ingredients[i] == 1 && new_ingredients[i] == 0)
            {
                new_ingredients[i] = 1;
                ways = (ways + count_ways(graph, time_left - travel_time, neighbor, new_ingredients)) % MOD;
            }
        }
    }

    memo[make_tuple(current_node, ingredients, time_left)] = ways;
    return ways;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    map<int, vector<tuple<int, vector<int>, int>>> graph;

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        string s;
        cin >> u >> v >> s;
        vector<int> shop_ingredients(4, 0);
        for (char c : s)
        {
            if (c == 'B')
            {
                shop_ingredients[0] = 1;
            }
            else if (c == 'E')
            {
                shop_ingredients[1] = 1;
            }
            else if (c == 'M')
            {
                shop_ingredients[2] = 1;
            }
            else if (c == 'J')
            {
                shop_ingredients[3] = 1;
            }
        }
        graph[u].emplace_back(v, shop_ingredients, 1);
        graph[u].emplace_back(v, shop_ingredients, 2);
    }

    int T;
    cin >> T;

    vector<int> ingredients(4, 0);
    int result = count_ways(graph, T, 1, ingredients);
    cout << result << endl;

    return 0;
}