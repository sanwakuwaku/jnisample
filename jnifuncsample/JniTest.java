class JniTest {
  private int intField;

  public JniTest(int num) {
    intField = num;
    System.out.println("[Java] JniTestオブジェクトのコンストラクタ呼び出し : intField = " + intField);
  }

  // JNIネイティブ関数から呼び出される
  public int callByNative(int num) {
    System.out.println("[Java] JniTestオブジェクトのcallByNative(" + num + ") 呼び出し");
    return num;
  }

  public void callTest(){
    System.out.println("[Java] JniTestオブジェクトのcallTest()メソッドの呼び出し: intField =" + intField);
  }
}
