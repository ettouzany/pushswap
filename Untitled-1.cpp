
//c++
void findLIS(vector<int> const &arr)
{
    int n = arr.size();
 
    if (n == 0) {
        return;
    }
 
    vector<vector<int>> LIS(n, vector<int>{});
 
    LIS[0].push_back(arr[0]);
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
 
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size()) {
                LIS[i] = LIS[j];
            }
        }
 
        LIS[i].push_back(arr[i]);
    }
 
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (LIS[j].size() < LIS[i].size()) {
            j = i;
        }
    }
 
    for (int i: LIS[j]) {
        cout << i << " ";
    }
}

//from c++  to c code

//c replace for loop with while loop
void findLIS(int arr[], int n)
{
    int *LIS = (int *)malloc(n * sizeof(int));
    int *index = (int *)malloc(n * sizeof(int));
    
    int i, j, max = 0;

    // for (i = 0; i < n; i++)
    // {
    //     LIS[i] = 1;
    //     index[i] = 0;
    // }
    while(i < n)
    {
        LIS[i] = 1;
        index[i] = 0;
        i++;
    }