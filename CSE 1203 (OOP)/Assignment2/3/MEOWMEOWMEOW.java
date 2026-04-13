import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.time.LocalDate;
import java.time.format.TextStyle;
import java.util.*;
import java.util.List;

interface ITrainTracker {
    void updateUIContent();
}

// Serializable allows these objects to be saved to a file
class Station implements Serializable {
    private static final long serialVersionUID = 1L;
    String name;

    Station(String name) {
        this.name = name;
    }
}

class Train implements Serializable {
    private static final long serialVersionUID = 1L;
    String number, name, startStation, destStation, depTime, arrTime, offDay, totalDist;
    List<Station> stops;
    int passedStops;
    String nextStat, nextStop, remainingInfo;

    Train(String number, String name, String start, String dep, String dest, String arr,
            String dist, String off, int passed, String nextStat, String nextStop, String rem, List<Station> stops) {
        this.number = number;
        this.name = name;
        this.startStation = start;
        this.depTime = dep;
        this.destStation = dest;
        this.arrTime = arr;
        this.totalDist = dist;
        this.offDay = off;
        this.passedStops = passed;
        this.nextStat = nextStat;
        this.nextStop = nextStop;
        this.remainingInfo = rem;
        this.stops = stops;
    }
}

public class MEOWMEOWMEOW extends JFrame implements ITrainTracker {

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
    private final String DATA_FILE = "train_data.dat"; // Permanent binary data file

    public MEOWMEOWMEOW() {
        setUndecorated(true);
        setSize(750, 480);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        initializeData();

        JPanel mainWrapper = new JPanel(new BorderLayout());
        mainWrapper.setBackground(SAGE_BG);
        mainWrapper.setBorder(new LineBorder(Color.BLACK, 1));

        // Header Setup
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

        // Sidebar Content
        JPanel content = new JPanel(null);
        content.setOpaque(false);

        JLabel selectLabel = new JLabel("Select Train");
        selectLabel.setBounds(25, 20, 150, 25);
        selectLabel.setFont(new Font("SansSerif", Font.PLAIN, 16));
        content.add(selectLabel);

        trainCombo = new JComboBox<>(new String[] { "754-Silkcity Express", "702-Subarna Express", "705-Ekota Express",
                "792-Banalata Express" });
        trainCombo.setBounds(25, 50, 210, 35);
        trainCombo.setFont(new Font("SansSerif", Font.BOLD, 14));
        trainCombo.addActionListener(e -> updateUIContent());
        content.add(trainCombo);

        logoLabel1 = new JLabel();
        logoLabel1.setBounds(40, 180, 80, 80);
        setScaledImage(logoLabel1, "govt_logo.png", 80);
        content.add(logoLabel1);

        logoLabel2 = new JLabel();
        logoLabel2.setBounds(140, 180, 80, 80);
        setScaledImage(logoLabel2, "railway_logo.png", 80);
        content.add(logoLabel2);

        JLabel copy = new JLabel("Copyright@2026, CSE RUET");
        copy.setBounds(25, 380, 200, 20);
        copy.setFont(new Font("SansSerif", Font.PLAIN, 12));
        content.add(copy);

        // Main Information Display
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

    @SuppressWarnings("unchecked")
    private void initializeData() {
        File f = new File(DATA_FILE);
        if (f.exists()) {
            // LOAD FROM FILE (Requirement f)
            try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(f))) {
                trainMap = (Map<String, Train>) in.readObject();
                return;
            } catch (Exception e) {
                System.err.println("Load error, resetting data.");
            }
        }

        // INITIAL DATA CREATION
        trainMap = new HashMap<>();
        List<Station> s754 = new ArrayList<>();
        for (int i = 1; i <= 12; i++)
            s754.add(new Station("S" + i));
        trainMap.put("754-Silkcity Express", new Train("754", "Silkcity Express", "Rajshahi", "07:40", "Dhaka", "13:20",
                "255 km", "Sunday", 7, "Solop", "Jamtail", "Remaining 126 km in 02:50 hours", s754));

        List<Station> s702 = new ArrayList<>();
        for (int i = 1; i <= 4; i++)
            s702.add(new Station("S" + i));
        trainMap.put("702-Subarna Express", new Train("702", "Subarna Express", "Chittagong", "07:00", "Dhaka", "12:20",
                "320 km", "Monday", 2, "Feni", "Comilla", "Remaining 45 km in 00:55 hours", s702));

        List<Station> s705 = new ArrayList<>();
        for (int i = 1; i <= 15; i++)
            s705.add(new Station("S" + i));
        trainMap.put("705-Ekota Express", new Train("705", "Ekota Express", "Dhaka", "10:15", "Dinajpur", "21:10",
                "430 km", "Tuesday", 4, "Tangail", "Sirajganj", "Remaining 310 km in 06:15 hours", s705));

        List<Station> s792 = new ArrayList<>();
        for (int i = 1; i <= 5; i++)
            s792.add(new Station("S" + i));
        trainMap.put("792-Banalata Express", new Train("792", "Banalata Express", "Chapainawabganj", "06:00", "Dhaka",
                "11:30", "302 km", "Friday", 3, "Rajshahi", "Mirzapur", "Remaining 80 km in 01:20 hours", s792));

        // SAVE TO FILE (Requirement f)
        saveData();
    }

    private void saveData() {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(DATA_FILE))) {
            out.writeObject(trainMap);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void updateUIContent() {
        dataGrid.removeAll();
        Train t = trainMap.get((String) trainCombo.getSelectedItem());
        String currentDay = LocalDate.now().getDayOfWeek().getDisplayName(TextStyle.FULL, Locale.ENGLISH);

        if (currentDay.equalsIgnoreCase(t.offDay)) {
            JLabel msg = new JLabel("TRAIN OFF DAY: " + t.offDay.toUpperCase());
            msg.setForeground(Color.RED);
            msg.setFont(new Font("SansSerif", Font.BOLD, 20));
            dataGrid.add(msg);
            remainingLabel.setText("Not Operating Today");
            trackPainter.setStats(0, t.stops.size());
        } else {
            String[] vals = { t.number, t.name, t.startStation, t.depTime, t.destStation, t.arrTime,
                    String.valueOf(t.stops.size()), t.nextStat, t.nextStop, t.totalDist };
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
            if (ratio > 1.0)
                ratio = 1.0;
            g2.setColor(new Color(255, 204, 0));
            g2.fillRect(xS, y, (int) (tW * ratio), 10);
            for (int i = 0; i < tt; i++) {
                int dX = (tt > 1) ? xS + (i * tW / (tt - 1)) : xS + (tW / 2);
                g2.setColor(i < p ? new Color(0, 153, 51) : Color.RED);
                g2.fillOval(dX - 6, y - 2, 12, 12);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new MEOWMEOWMEOW().setVisible(true));
    }
}