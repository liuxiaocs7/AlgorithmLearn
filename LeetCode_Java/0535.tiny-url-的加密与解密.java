/*
 * @lc app=leetcode.cn id=535 lang=java
 *
 * [535] TinyURL 的加密与解密
 */

// @lc code=start
public class Codec {
    Map<String, String> origin2Tiny = new HashMap<>();
    Map<String, String> tiny2Origin = new HashMap<>();

    int k = 6;
    String str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    Random random = new Random();

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        char[] cs = new char[k];
        while(!origin2Tiny.containsKey(longUrl)) {
            for(int i = 0; i < k; i++) {
                cs[i] = str.charAt(random.nextInt(str.length()));
            }
            String shortUrl = String.valueOf(cs);
            if(tiny2Origin.containsKey(shortUrl)) continue;
            tiny2Origin.put(shortUrl, longUrl);
            origin2Tiny.put(longUrl, shortUrl);
        }
        return origin2Tiny.get(longUrl);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return tiny2Origin.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
// @lc code=end

