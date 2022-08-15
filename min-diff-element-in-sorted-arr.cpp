int binarySearchMinDifference(int arr[], int key) {
        int n = arr.size();

        if(key < arr[0]) { return arr[0]; }
        if(key > arr[n - 1]) { return arr[n - 1]; }

        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(key == arr[mid]) { return arr[mid]; }
            else if(key < arr[mid]) { end = mid - 1; }
            else { start = mid + 1; }
        }

        if (abs(arr[start] - key) < abs(arr[end]-key)) { return arr[start]; }
        return arr[end];
    }