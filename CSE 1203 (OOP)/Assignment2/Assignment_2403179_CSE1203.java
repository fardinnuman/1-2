import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.time.LocalDate;
import java.time.format.TextStyle;
import java.util.*;
import java.util.List;

// INTERFACE
interface ITrainTracker {
    void updateUIContent();
}

// ABSTRACT CLASS
abstract class RailwayEntity {
    protected String name;

    public RailwayEntity(String name) {
        this.name = name;
    }

    public abstract String getEntityType();

    public String getName() {
        return name;
    }
}

// STATION CLASS
class Station {
    String name;

    Station(String name) {
        this.name = name;
    }
}

// TRAIN CLASS
class Train extends RailwayEntity {
    String number, name, startStation, departureTime, destinationStation, arrivalTime, offDay, totalDistance;
    List<Station> stops;
    int passedStops;
    String nextStation, nextStop, remainingInfo;

    Train(String number, String name, String start, String dep, String dest, String arr,
            String dist, String off, int passed, String nextStation, String nextStop, String rem, List<Station> stops) {
        super(name);
        this.number = number;
        this.name = name;
        this.startStation = start;
        this.departureTime = dep;
        this.destinationStation = dest;
        this.arrivalTime = arr;
        this.totalDistance = dist;
        this.offDay = off;
        this.passedStops = passed;
        this.nextStation = nextStation;
        this.nextStop = nextStop;
        this.remainingInfo = rem;
        this.stops = stops;
    }

    @Override
    public String getEntityType() {
        return "Train";
    }

    public String toFileString() {
        return String.format(
                "%-3s | %-17s | %-16s | %-5s | %-8s | %-5s | %-6s | %-8s | %-1s | %-8s | %-15s | %-31s | %-2s",
                number, name, startStation, departureTime, destinationStation, arrivalTime,
                totalDistance, offDay, passedStops, nextStation, nextStop, remainingInfo, stops.size());
    }
}

public class Assignment_2403179_CSE1203 extends JFrame implements ITrainTracker {

    private final Color MAROON_HEADER = new Color(114, 43, 43);
    private final Color SAGE_BG = new Color(196, 213, 184);
    private final Color DARK_PANEL = new Color(54, 57, 59);
    private final Color VALUE_CYAN = new Color(110, 197, 226);
    private final Color BORDER_BLUE = new Color(70, 110, 150);

    private JComboBox<String> trainCombo;
    private JLabel remainingLabel, logoLabel1, logoLabel2;
    private JPanel dataGrid;
    private TrackPainter trackPainter;
    private Map<String, Train> trainMap;
    private int pX, pY;
    private final String DATA_FILE = "train-data.txt";

    public Assignment_2403179_CSE1203() {
        setUndecorated(true);
        setSize(750, 480);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        initializeData();

        JPanel mainWrapper = new JPanel(new BorderLayout());
        mainWrapper.setBackground(SAGE_BG);
        mainWrapper.setBorder(new LineBorder(Color.BLACK, 1));

        JPanel header = new JPanel(new BorderLayout());
        header.setBackground(MAROON_HEADER);
        header.setPreferredSize(new Dimension(0, 40));
        header.addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent me) {
                pX = me.getX();
                pY = me.getY();
            }
        });
        header.addMouseMotionListener(new MouseAdapter() {
            public void mouseDragged(MouseEvent me) {
                setLocation(getLocation().x + me.getX() - pX, getLocation().y + me.getY() - pY);
            }
        });

        JLabel title = new JLabel("       Bangladesh Train Tracker", SwingConstants.CENTER);
        title.setForeground(Color.WHITE);
        title.setFont(new Font("Arial", Font.BOLD, 18));
        header.add(title, BorderLayout.CENTER);

        JPanel btnPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT, 15, 5));
        btnPanel.setOpaque(false);

        JLabel minBtn = new JLabel("-", SwingConstants.CENTER);
        minBtn.setForeground(Color.WHITE);
        minBtn.setFont(new Font("Monospaced", Font.BOLD, 22));
        minBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        minBtn.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                setState(Frame.ICONIFIED);
            }
        });

        JLabel clsBtn = new JLabel("x", SwingConstants.CENTER);
        clsBtn.setForeground(Color.WHITE);
        clsBtn.setFont(new Font("Arial", Font.PLAIN, 20));
        clsBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        clsBtn.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                System.exit(0);
            }
        });

        btnPanel.add(clsBtn);
        btnPanel.add(minBtn);
        header.add(btnPanel, BorderLayout.EAST);

        JPanel content = new JPanel(null);
        content.setOpaque(false);

        JLabel selectLabel = new JLabel("Select Train");
        selectLabel.setBounds(25, 20, 150, 25);
        selectLabel.setFont(new Font("SansSerif", Font.PLAIN, 16));
        content.add(selectLabel);

        trainCombo = new JComboBox<>(
                new String[] { "756-Madhumati Express", "792-Banalata Express", "754-Silkcity Express",
                        "760-Padma Express" });
        trainCombo.setBounds(25, 50, 210, 35);
        trainCombo.setFont(new Font("SansSerif", Font.BOLD, 14));
        trainCombo.addActionListener(e -> updateUIContent());
        content.add(trainCombo);

        logoLabel1 = new JLabel();
        logoLabel1.setBounds(40, 180, 80, 80);
        setScaledImage(logoLabel1, "govtLogo.png", 80);
        content.add(logoLabel1);

        logoLabel2 = new JLabel();
        logoLabel2.setBounds(140, 180, 80, 80);
        setScaledImage(logoLabel2, "railwayLogo.png", 80);
        content.add(logoLabel2);

        JLabel copy = new JLabel(
                "<html><b>SUBMITTED BY:<br>FARDIN BIN ASLAM NUMAN<br>2403179 | CSE-C | 24 SERIES</b><br><br>Copyright @ 2026, CSE RUET</html>");

        copy.setBounds(25, 330, 200, 80);
        copy.setFont(new Font("SansSerif", Font.PLAIN, 12));
        content.add(copy);

        JPanel infoPanel = new JPanel(new BorderLayout());
        infoPanel.setBounds(260, 15, 460, 400);
        infoPanel.setBackground(DARK_PANEL);
        infoPanel.setBorder(new LineBorder(BORDER_BLUE, 3));

        dataGrid = new JPanel(new GridBagLayout());
        dataGrid.setOpaque(false);
        infoPanel.add(dataGrid, BorderLayout.CENTER);

        JPanel bottom = new JPanel(new BorderLayout());
        bottom.setBackground(new Color(220, 220, 220));
        bottom.setPreferredSize(new Dimension(0, 80));

        trackPainter = new TrackPainter();
        remainingLabel = new JLabel("", SwingConstants.CENTER);
        remainingLabel.setFont(new Font("SansSerif", Font.BOLD, 14));
        remainingLabel.setBorder(new EmptyBorder(0, 0, 5, 0));

        bottom.add(trackPainter, BorderLayout.CENTER);
        bottom.add(remainingLabel, BorderLayout.SOUTH);
        infoPanel.add(bottom, BorderLayout.SOUTH);
        content.add(infoPanel);

        mainWrapper.add(header, BorderLayout.NORTH);
        mainWrapper.add(content, BorderLayout.CENTER);
        add(mainWrapper);

        updateUIContent();
    }

    private void setScaledImage(JLabel label, String path, int size) {
        try {
            ImageIcon icon = new ImageIcon(path);
            Image img = icon.getImage().getScaledInstance(size, size, Image.SCALE_SMOOTH);
            label.setIcon(new ImageIcon(img));
        } catch (Exception e) {
            label.setText("No Logo");
        }
    }

    private void initializeData() {
        trainMap = new HashMap<>();
        File file = new File(DATA_FILE);

        if (file.exists()) {
            try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
                reader.readLine();
                reader.readLine();
                String line;
                while ((line = reader.readLine()) != null) {
                    String[] d = line.split("\\s*\\|\\s*");
                    if (d.length < 13)
                        continue;
                    List<Station> stops = new ArrayList<>();
                    int stopCount = Integer.parseInt(d[12].trim());
                    for (int i = 0; i < stopCount; i++)
                        stops.add(new Station("S"));
                    Train t = new Train(d[0].trim(), d[1].trim(), d[2].trim(), d[3].trim(), d[4].trim(), d[5].trim(),
                            d[6].trim(), d[7].trim(), Integer.parseInt(d[8].trim()), d[9].trim(), d[10].trim(),
                            d[11].trim(), stops);
                    trainMap.put(d[0].trim() + "-" + d[1].trim(), t);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else {
            createDefaultData();
            saveToTxtFile();
        }
    }

    private void createDefaultData() {
        trainMap = new HashMap<>();

        // TRAIN INFORMATIONS FROM https://eticket.railway.gov.bd/ WEBSITE (RAJSHAHI TO DHAKA)
        // MADHUMATI EXPRESS
        List<Station> s1 = new ArrayList<>();
        String[] madhumatiStations = { "Rajshahi", "Ishwardi", "Paksey", "Bheramara", "Mirpur",
                "Poradaha", "Kushtia Court", "Kumarkhali", "Khoksha", "Pangsha",
                "Kalukhali", "Rajbari", "Pachuria", "Amirabad", "Faridpur",
                "Talma", "Pukuria", "Bhanga", "Shibchar", "Padma",
                "Mawa", "Sreenagar", "Dhaka" };
        for (String station : madhumatiStations)
            s1.add(new Station(station));
        trainMap.put("756-Madhumati Express",
                new Train("756", "Madhumati Express", "Rajshahi", "06:40", "Dhaka", "14:00", "220 km", "Saturday", 5,
                        "Poradaha", "Kushtia Court", "Remaining 170 km in 05:10 hours", s1));

        // BANALATA EXPRESS
        List<Station> s2 = new ArrayList<>();
        String[] banalataStations = { "Chapainawabganj", "Rajshahi", "Dhaka" };
        for (String station : banalataStations)
            s2.add(new Station(station));
        trainMap.put("792-Banalata Express", new Train("792", "Banalata Express", "Chapainawabganj", "06:00", "Dhaka",
                "11:35", "320 km", "Friday", 1, "Rajshahi", "Dhaka", "Remaining 280 km in 04:45 hours", s2));

        // SILKCITY EXPRESS
        List<Station> s3 = new ArrayList<>();
        String[] silkcityStations = { "Rajshahi", "Abdulpur", "Ishwardi", "Chatmohar", "Boral Bridge", "Ullapara",
                "Jamtail", "SHM Monsur Ali", "Ibrahimabad",
                "Tangail", "Mirzapur", "Joydebpur", "Dhaka" };
        for (String station : silkcityStations)
            s3.add(new Station(station));
        trainMap.put("754-Silkcity Express", new Train("754", "Silkcity Express", "Rajshahi", "07:40", "Dhaka", "13:20",
                "220 km", "Sunday", 7, "Ullapara", "Jamtail", "Remaining 126 km in 02:50 hours", s3));

        // PADMA EXPRESS
        List<Station> s4 = new ArrayList<>();
        String[] padmaStations = { "Rajshahi", "Sardah Road", "Abdulpur", "Ishwardi Bypass", "Chatmohar",
                "Boral Bridge", "Ullapara", "SHM Monsur Ali", "Ibrahimabad", "Tangail",
                "Joydebpur", "Dhaka" };
        for (String station : padmaStations)
            s4.add(new Station(station));
        trainMap.put("760-Padma Express", new Train("760", "Padma Express", "Rajshahi", "16:00", "Dhaka", "21:15",
                "220 km", "Tuesday", 5, "Ullapara", "SHM Monsur Ali", "Remaining 145 km in 03:20 hours", s4));

        saveToTxtFile();
    }

    // TO SAVE TRAIN-DATA TO train-data.txt FILE
    private void saveToTxtFile() {
        try (PrintWriter writer = new PrintWriter(new FileWriter(DATA_FILE))) {

            writer.println(
                    "ID  | Name              | Start Station    | Dep   | Dest     | Arr   | Dist   | Off Day  | # | Next St. | Next Sp.        | Progress Info                   | Stops");
            writer.println(
                    "---------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            for (Train t : trainMap.values()) {
                writer.println(t.toFileString());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void updateUIContent() {
        dataGrid.removeAll();
        Train t = trainMap.get((String) trainCombo.getSelectedItem());

        // TO EXTRACT DAY FROM THE SYSTEM
        String currentDay = LocalDate.now().getDayOfWeek().getDisplayName(TextStyle.FULL, Locale.ENGLISH);

        // TO DISPLAY MESSAGE FOR TRAIN OFF DAY
        if (currentDay.equalsIgnoreCase(t.offDay)) {
            JLabel msg = new JLabel("TRAIN OFF DAY: " + t.offDay.toUpperCase());
            msg.setForeground(Color.RED);
            msg.setFont(new Font("SansSerif", Font.BOLD, 20));
            dataGrid.add(msg);
            remainingLabel.setText("Not Operating Today");
            trackPainter.setStats(0, t.stops.size());
        } else {
            String[] vals = { t.number, t.name, t.startStation, t.departureTime, t.destinationStation, t.arrivalTime,
                    String.valueOf(t.stops.size()), t.nextStation, t.nextStop, t.totalDistance };
            String[] keys = { "1. Train Number:", "2. Train Name:", "3. Start Station:", "4. Time of Departure:",
                    "5. Destination Station:", "6. Time of Arrival:", "7. Number of Stops:", "8. Next Station:",
                    "9. Next Stop:", "10. Total Distance:" };

            GridBagConstraints gbc = new GridBagConstraints();
            gbc.fill = GridBagConstraints.HORIZONTAL;
            gbc.insets = new Insets(3, 20, 3, 10);

            for (int i = 0; i < keys.length; i++) {
                JLabel k = new JLabel(keys[i]);
                k.setForeground(Color.WHITE);
                k.setFont(new Font("SansSerif", Font.PLAIN, 15));
                k.setPreferredSize(new Dimension(170, 22));
                gbc.gridx = 0;
                gbc.gridy = i;
                gbc.weightx = 0;
                dataGrid.add(k, gbc);

                JLabel v = new JLabel(vals[i]);
                v.setForeground(VALUE_CYAN);
                v.setFont(new Font("SansSerif", Font.BOLD, 15));
                gbc.gridx = 1;
                gbc.weightx = 1.0;
                dataGrid.add(v, gbc);
            }
            remainingLabel.setText(t.remainingInfo);
            trackPainter.setStats(t.passedStops, t.stops.size());
        }
        dataGrid.revalidate();
        dataGrid.repaint();
    }

    class TrackPainter extends JPanel {
        private int p, tt;

        public void setStats(int p, int tt) {
            this.p = p;
            this.tt = tt;
            this.repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (tt <= 0)
                return;
            Graphics2D g2 = (Graphics2D) g;
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            int y = getHeight() / 2 - 4, xS = 20, xE = getWidth() - 20, tW = xE - xS;
            g2.setColor(new Color(80, 80, 80));
            g2.fillRect(xS, y, tW, 10);
            double ratio = (tt > 1) ? (double) (p - 0.6) / (tt - 1) : 0;
            g2.setColor(new Color(255, 204, 0));
            g2.fillRect(xS, y, (int) (tW * Math.min(1.0, ratio)), 10);
            for (int i = 0; i < tt; i++) {
                int dX = (tt > 1) ? xS + (i * tW / (tt - 1)) : xS + (tW / 2);
                g2.setColor(i < p ? new Color(0, 153, 51) : Color.RED);
                g2.fillOval(dX - 6, y - 2, 12, 12);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Assignment_2403179_CSE1203().setVisible(true));
    }
}