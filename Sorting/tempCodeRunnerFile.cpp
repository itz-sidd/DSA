int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read input
    }

    bubblesort(arr, n); // Sort

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print sorted array
    }
    cout << endl;

    return 0;
}