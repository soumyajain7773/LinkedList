class Solution {
  String makeLargestSpecial(String s) {
    if (s.length <= 2) return s;

    List<String> subs = [];
    int count = 0;
    int start = 0;

    for (int i = 0; i < s.length; i++) {
      if (s[i] == '1') count++;
      else count--;

      if (count == 0) {
        // recursive call
        String inner = makeLargestSpecial(s.substring(start + 1, i));
        subs.add("1" + inner + "0");
        start = i + 1;
      }
    }

    // sort in descending order
    subs.sort((a, b) => b.compareTo(a));

    return subs.join();
  }
}