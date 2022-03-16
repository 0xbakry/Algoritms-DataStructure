import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.logging.Level;
import java.util.logging.Logger;
 

/**
 *
 * @author omarbakry
 */

class Node
{
    Character data;
    Integer freq;
    Node child0 = null, child1 = null;
 
    Node(Character ch, Integer freq)
    {
        this.data = ch;
        this.freq = freq;
    }
 
    public Node(Character ch, Integer freq, Node left, Node right)
    {
        this.data = ch;
        this.freq = freq;
        this.child0 = left;
        this.child1 = right;
    }
}
 
class Main
{
     
    public static void encode(Node root, String word, Map<Character, String> huffmanCode)
    {
        if (root == null)
            return;

        if (isLeaf(root))
            huffmanCode.put(root.data, word.length() > 0 ? word : "1");
        
        encode(root.child0, word + '0', huffmanCode);
        encode(root.child1, word+ '1', huffmanCode);
    }
 

    public static int decode(Node root, int index, StringBuilder sb)
    {
        if (root == null) 
            return index;
        
        if (isLeaf(root))
        {
            
            System.out.print(root.data);
            return index;
        }
 
        index++;
 
        root = (sb.charAt(index) == '0') ? root.child0 : root.child1;
        index = decode(root, index, sb);
        return index;
    }
 
    public static boolean isLeaf(Node root) {
        return root.child0 == null && root.child1 == null;
    }
 
    public static void buildHuffmanTree(String text)
    {
       File file = new File("E:\\Materiales\\DC\\out.txt");
       BufferedWriter bf = null;
       
        if (text == null || text.length() == 0) 
            return;

        Map<Character, Integer> freq = new HashMap<>();
        for (char c: text.toCharArray()) 
            freq.put(c, freq.getOrDefault(c, 0) + 1);

            System.out.println("The prob for each char is: " +freq);
 
        
        PriorityQueue<Node> pq;
        pq = new PriorityQueue<>(Comparator.comparingInt(l -> l.freq));
 
        for (var entry: freq.entrySet()) 
            pq.add(new Node(entry.getKey(), entry.getValue()));
        
 
        while (pq.size() != 1)
        {
            Node left = pq.poll();
            Node right = pq.poll();
 
            int sum = left.freq + right.freq;
            pq.add(new Node(null, sum, left, right));
            
            
        }
         while (pq.size() != 1)
         {
             Node node = pq.poll();
              System.out.println(node.freq);
         }
       
        Node root = pq.peek();
 
        Map<Character, String> huffmanCode = new HashMap<>();
        encode(root, "", huffmanCode);
        
        StringBuilder sb = new StringBuilder();
        for (char c: text.toCharArray()) {
            sb.append(huffmanCode.get(c));
        }
        
        try {
                bf = new BufferedWriter(new FileWriter(file));

                for (Map.Entry<Character, String> entry : huffmanCode.entrySet())
                {
                    bf.write(entry.getKey() + ":"
                             + entry.getValue());

                    bf.newLine();
                }
                
                  bf.write(sb.toString());

                bf.flush();
        }
     
        catch (IOException e)
        {
            e.printStackTrace();
        }
        finally 
        {
  
            try
            {
                bf.close();
            }
            catch (Exception e) {
            }
        }

         
        if (isLeaf(root))
        {
  
            while (root.freq-- > 0) 
                System.out.print(root.data);
            
        }
        else
        {
            System.out.println("The orginal text is: ");
            int index = -1;
            while (index < sb.length() - 1) {
                index = decode(root, index, sb);
            }
        }
        
        Integer compressed = freq.values().stream()
        .mapToInt(Integer::valueOf)
        .sum();
        
        int uncompressed = text.length() * 3;
        float ratio = uncompressed / compressed;
        
       System.out.print("\n"  + "The Compression Ratio is: " + ratio);

    }
 
   
    
    public static void main(String[] args) throws IOException
    {
         Path fileName = Path.of("E:\\Materiales\\DC\\input.txt");
         String word = Files.readString(fileName);
         

        buildHuffmanTree(word);
    }
}