int smallestSubWithSum(int arr[], int n, int x)

    {

        int currn_sum = 0;

        int j = 0;

        int length = n;

        for(int i = 0 ; i < n ; i++){

            currn_sum +=arr[i];

            if(currn_sum > x){

                while(currn_sum - arr[j] > x){

                    currn_sum = currn_sum - arr[j];

                    j++;

                }

                if(length > i - j){

                    length = i - j;

                }

            }

        }

        return length + 1;

    }
