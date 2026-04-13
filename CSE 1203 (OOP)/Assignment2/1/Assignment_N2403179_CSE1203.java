import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.util.HashMap;
import java.util.Map;

public class Assignment_N2403179_CSE1203 extends JFrame {

    private final Color MAROON_HEADER = new Color(114, 43, 43);
    private final Color SAGE_BG = new Color(196, 213, 184);
    private final Color DARK_PANEL = new Color(54, 57, 59);
    private final Color VALUE_CYAN = new Color(110, 197, 226);
    private final Color BORDER_BLUE = new Color(70, 110, 150);

    private JComboBox<String> trainCombo;
    private JLabel remainingLabel, logoLabel1, logoLabel2;
    private JPanel dataGrid;
    private TrackPainter trackPainter;
    private Map<String, String[]> trainDataMap;

    private int pX, pY;

    public Assignment_N2403179_CSE1203() {
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
        header.setPreferredSize(new Dimension(0, 40)); // Slightly thinner header

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

        JPanel btnPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT, 15, 5)); // Reduced v-gap to 5
        btnPanel.setOpaque(false);

        JLabel minimizeBtn = new JLabel("-", SwingConstants.CENTER);
        minimizeBtn.setForeground(Color.WHITE);
        minimizeBtn.setFont(new Font("Monospaced", Font.BOLD, 22));
        minimizeBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        minimizeBtn.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                setState(Frame.ICONIFIED);
            }
        });

        JLabel closeBtn = new JLabel("x", SwingConstants.CENTER);
        closeBtn.setForeground(Color.WHITE);
        closeBtn.setFont(new Font("Arial", Font.PLAIN, 20));
        closeBtn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        closeBtn.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                System.exit(0);
            }
        });

        btnPanel.add(closeBtn);
        btnPanel.add(minimizeBtn);
        header.add(btnPanel, BorderLayout.EAST);

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
        logoLabel1.setBounds(40, 180, 80, 80); // Scaled logos down
        setScaledImage(logoLabel1, "govt_logo.png", 80);
        content.add(logoLabel1);

        logoLabel2 = new JLabel();
        logoLabel2.setBounds(140, 180, 80, 80);
        setScaledImage(logoLabel2, "railway_logo.png", 80);
        content.add(logoLabel2);

        JLabel copyright = new JLabel("Copyright@2026, CSE RUET");
        copyright.setBounds(25, 380, 200, 20);
        copyright.setFont(new Font("SansSerif", Font.PLAIN, 12));
        content.add(copyright);

        JPanel infoPanel = new JPanel(new BorderLayout());
        infoPanel.setBounds(260, 15, 460, 400);
        infoPanel.setBackground(DARK_PANEL);
        infoPanel.setBorder(new LineBorder(BORDER_BLUE, 3));

        dataGrid = new JPanel(new GridBagLayout());
        dataGrid.setOpaque(false);
        infoPanel.add(dataGrid, BorderLayout.CENTER);

        JPanel bottomSection = new JPanel(new BorderLayout());
        bottomSection.setBackground(new Color(220, 220, 220));
        bottomSection.setPreferredSize(new Dimension(0, 80));

        trackPainter = new TrackPainter();
        remainingLabel = new JLabel("", SwingConstants.CENTER);
        remainingLabel.setFont(new Font("SansSerif", Font.BOLD, 14));
        remainingLabel.setBorder(new EmptyBorder(0, 0, 5, 0));

        bottomSection.add(trackPainter, BorderLayout.CENTER);
        bottomSection.add(remainingLabel, BorderLayout.SOUTH);

        infoPanel.add(bottomSection, BorderLayout.SOUTH);
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
        trainDataMap = new HashMap<>();
        trainDataMap.put("754-Silkcity Express", new String[] { "754", "Silkcity Express", "Rajshahi", "07:40", "Dhaka",
                "13:20", "12", "Solop", "Jamtail", "255 km", "Remaining 126 km in 02:50 hours", "7", "12" });
        trainDataMap.put("702-Subarna Express", new String[] { "702", "Subarna Express", "Chittagong", "07:00", "Dhaka",
                "12:20", "2", "Feni", "Comilla", "320 km", "Remaining 45 km in 00:55 hours", "2", "4" });
        trainDataMap.put("705-Ekota Express", new String[] { "705", "Ekota Express", "Dhaka", "10:15", "Dinajpur",
                "21:10", "15", "Tangail", "Sirajganj", "430 km", "Remaining 310 km in 06:15 hours", "4", "15" });
        trainDataMap.put("792-Banalata Express", new String[] { "792", "Banalata Express", "Chapainawabganj", "06:00",
                "Dhaka", "11:30", "2", "Rajshahi", "Mirzapur", "302 km", "Remaining 80 km in 01:20 hours", "3", "5" });
    }

    private void updateUIContent() {
        dataGrid.removeAll();
        String[] d = trainDataMap.get((String) trainCombo.getSelectedItem());
        String[] labels = { "1. Train Number:", "2. Train Name:", "3. Start Station:", "4. Time of Departure:",
                "5. Destination Station:", "6. Time of Arrival:", "7. Number of Stops:", "8. Next Station:",
                "9. Next Stop:", "10. Total Distance:" };

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(3, 20, 3, 10); // Reduced insets for smaller window

        for (int i = 0; i < labels.length; i++) {
            JLabel key = new JLabel(labels[i]);
            key.setForeground(Color.WHITE);
            key.setFont(new Font("SansSerif", Font.PLAIN, 15));
            key.setPreferredSize(new Dimension(170, 22));
            gbc.gridx = 0;
            gbc.gridy = i;
            gbc.weightx = 0;
            dataGrid.add(key, gbc);

            JLabel val = new JLabel(d[i]);
            val.setForeground(VALUE_CYAN);
            val.setFont(new Font("SansSerif", Font.BOLD, 15));
            gbc.gridx = 1;
            gbc.weightx = 1.0;
            dataGrid.add(val, gbc);
        }
        remainingLabel.setText(d[10]);
        trackPainter.setStats(Integer.parseInt(d[11]), Integer.parseInt(d[12]));
        dataGrid.revalidate();
        dataGrid.repaint();
    }

    class TrackPainter extends JPanel {
        private int passed = 7, total = 12;

        public void setStats(int p, int t) {
            this.passed = p;
            this.total = t;
            this.repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D) g;
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            int y = getHeight() / 2 - 4, xStart = 20, xEnd = getWidth() - 20, trackWidth = xEnd - xStart;

            g2.setColor(new Color(80, 80, 80));
            g2.fillRect(xStart, y, trackWidth, 10);

            double progressRatio = (double) (passed - 0.6) / (total - 1);

            if (progressRatio > 1.0)
                progressRatio = 1.0;

            int yellowWidth = (int) (trackWidth * progressRatio);
            g2.setColor(new Color(255, 204, 0));
            g2.fillRect(xStart, y, yellowWidth, 10);

            for (int i = 0; i < total; i++) {
                int dotX = xStart + (i * trackWidth / (total - 1));
                g2.setColor(i < passed ? new Color(0, 153, 51) : Color.RED);
                g2.fillOval(dotX - 6, y - 2, 12, 12);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new Assignment_N2403179_CSE1203().setVisible(true));
    }
}