// Sample image data (replace with your actual images)
const images = [
    { src: 'https://source.unsplash.com/random/600x600/?nature', alt: 'Nature' },
    { src: 'https://source.unsplash.com/random/600x600/?city', alt: 'City' },
    { src: 'https://source.unsplash.com/random/600x600/?animal', alt: 'Animal' },
    { src: 'https://source.unsplash.com/random/600x600/?food', alt: 'Food' },
    { src: 'https://source.unsplash.com/random/600x600/?travel', alt: 'Travel' },
    { src: 'https://source.unsplash.com/random/600x600/?architecture', alt: 'Architecture' },
    { src: 'https://source.unsplash.com/random/600x600/?technology', alt: 'Technology' },
    { src: 'https://source.unsplash.com/random/600x600/?art', alt: 'Art' }
];

// Get DOM elements
const gallery = document.getElementById('gallery');
const modal = document.getElementById('modal');
const modalImage = document.getElementById('modalImage');
const caption = document.getElementById('caption');
const closeBtn = document.getElementById('closeBtn');

// Create gallery items
function createGallery() {
    images.forEach((image, index) => {
        const galleryItem = document.createElement('div');
        galleryItem.className = 'gallery-item';
        
        const img = document.createElement('img');
        img.src = image.src;
        img.alt = image.alt;
        img.className = 'gallery-img';
        img.dataset.index = index;
        
        galleryItem.appendChild(img);
        gallery.appendChild(galleryItem);
        
        // Add click event to each image
        img.addEventListener('click', () => {
            openModal(image.src, image.alt);
        });
    });
}

// Open modal with clicked image
function openModal(src, alt) {
    modal.style.display = 'block';
    modalImage.src = src;
    caption.textContent = alt;
    document.body.style.overflow = 'hidden';
}

// Close modal
function closeModal() {
    modal.style.display = 'none';
    document.body.style.overflow = 'auto';
}

// Event listeners
closeBtn.addEventListener('click', closeModal);
modal.addEventListener('click', (e) => {
    if (e.target === modal) {
        closeModal();
    }
});

// Keyboard navigation
document.addEventListener('keydown', (e) => {
    if (modal.style.display === 'block') {
        if (e.key === 'Escape') {
            closeModal();
        }
    }
});

// Initialize gallery
createGallery();
