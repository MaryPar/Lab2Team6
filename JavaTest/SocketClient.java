import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import org.json.JSONObject;

public class SocketClient {

    private final String swarmURL = "http://172.16.0.1:8001/FieldData/GetData";

    public void getData() throws Exception {

        URL obj = new URL(this.swarmURL);
        HttpURLConnection con = (HttpURLConnection) obj.openConnection();
        con.setRequestMethod("GET");
        con.setRequestProperty("User-Agent", "Mozilla/5.0");
        int responseCode = con.getResponseCode();
        System.out.println("\nSending GET request to URL: " + this.swarmURL);
        System.out.println("Response Code: " + responseCode);
        BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
        String inputline;
        StringBuffer response = new StringBuffer();
        while ((inputline = in.readLine()) != null) {
            response.append(inputline);
        }
        in.close();
        System.out.println(response.toString());
        JSONObject fieldData = new JSONObject(response.toString());

    }

}