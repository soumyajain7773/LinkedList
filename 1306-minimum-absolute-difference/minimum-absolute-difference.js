var minimumAbsDifference = function(arr) {
    arr.sort((a, b) => a - b);

    let minDiff = Infinity;

    // Find minimum difference
    for (let i = 1; i < arr.length; i++) {
        minDiff = Math.min(minDiff, arr[i] - arr[i - 1]);
    }

    const res = [];

    // Collect pairs
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] - arr[i - 1] === minDiff) {
            res.push([arr[i - 1], arr[i]]);
        }
    }

    return res;
};
