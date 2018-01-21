public class JniFuncMain {
  private static int staticIntField = 300;

  static {
    // ネイティブライブラリのロード
    System.loadLibrary("jnifunc");
  }

  // ネイティブメソッドの宣言
  public static native JniTest createJniObject();

  public static void main(String args[]) {
    System.out.println("[Java] createJniObject() ネイティブメソッドの呼び出し");
    // ネイティブコードからJniTestオブジェクトの生成
    JniTest jniObj = createJniObject();

    jniObj.callTest();
  }
}
